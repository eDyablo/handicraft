#pragma once

#include "token_tree.hpp"
#include <algorithm>
#include <functional>
#include <iterator>

#include <iostream>

namespace calc {
  template<typename Token>
  struct parser_t {
    typedef Token token_t;
    typedef typename token_t::symbol_t symbol_t;
    typedef struct token_tree_t<symbol_t> tree_t;
    typedef typename tree_t::node_t node_t;
    typedef typename tree_t::node_ref_t node_ref_t;

    tree_t tree;
    node_ref_t current;

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
        } else {
          if (token.contains('*') || token.contains('/')) {
            new_node.left = tree.node(current).right;
            auto const right = tree.add(new_node);
            tree.node(current).right = right;
            current = right;
          } else {
            new_node.left = current;
            current = tree.add(new_node);
          }
        }
      }
    }
  };

  template<typename InputIterator>
  auto parse(InputIterator first, InputIterator last) {
    using namespace std;
    typedef typename std::iterator_traits<InputIterator>::value_type token_t;
    typedef struct parser_t<token_t> parser_t;
    auto bracket_count = 0;
    auto parser = parser_t();
    for_each(first, last, bind(&parser_t::parse, &parser, placeholders::_1));
    return parser.tree;
  }
}
