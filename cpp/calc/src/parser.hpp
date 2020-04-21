#pragma once

#include "token_tree.hpp"
#include <algorithm>
#include <functional>
#include <iterator>
#include <stack>

namespace calc {
  template<typename Token>
  struct parser_t {
    typedef Token token_t;
    typedef typename token_t::symbol_t symbol_t;
    typedef struct token_tree_t<symbol_t> tree_t;
    typedef typename tree_t::node_t node_t;
    typedef typename tree_t::node_ref_t node_ref_t;
    typedef std::stack<node_ref_t> ref_stack_t;

    tree_t tree;
    node_ref_t current;
    ref_stack_t root_stack;

    parser_t():
    current(tree.add(node_t(token_t()))) {
    }

    void parse(token_t const& token) {
      node_t new_node(token);
      if (number == token.kind) {
        if (tree.no_node_ref == tree.node(current).left) {
          auto const left = tree.add(new_node);
          tree.node(current).left = left;
        } else {
          auto const right = tree.add(new_node);
          tree.node(current).right = right;
        }
      } else if (operation == token.kind) {
        if (unknown == tree.node(current).token.kind) {
          tree.node(current).token = token;
          tree.root = current;
        } else {
          if (higher_precedence(token, tree.node(current).token)) {
            new_node.left = tree.node(current).right;
            auto const right = tree.add(new_node);
            tree.node(current).right = right;
            current = right;
          } else {
            new_node.left = tree.root;
            current = tree.add(new_node);
            tree.root = current;
          }
        }
      } else if (open_bracket == token.kind) {
        root_stack.push(tree.root);
        current = tree.add(node_t(token_t()));
      } else if (close_bracket == token.kind) {
        auto const sub_tree = tree.root;
        tree.root = root_stack.top();
        root_stack.pop();
        tree.node(tree.root).right = sub_tree;
        current = tree.root;
      }
    }

    bool higher_precedence(token_t const& first, token_t const& second) {
      auto const& first_symbol = first.symbols.front();
      auto const& second_symbol = second.symbols.front(); 
      return first_symbol == '/' || (first_symbol == '*' && second_symbol != '/');
    }
  };

  template<typename InputIterator>
  auto parse(InputIterator first, InputIterator last) {
    using namespace std;
    typedef typename std::iterator_traits<InputIterator>::value_type token_t;
    typedef struct parser_t<token_t> parser_t;
    parser_t parser;
    for_each(first, last, bind(&parser_t::parse, &parser, placeholders::_1));
    return parser.tree;
  }

  template<typename Token>
  auto parse(std::vector<Token> const& tokens) {
    return parse(tokens.cbegin(), tokens.cend());
  }
}
