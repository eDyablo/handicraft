#pragma once

#include "token_tree.hpp"
#include <sstream>

namespace calc {
  template<typename Symbol>
  struct evaluator_t {
    typedef Symbol symbol_t;
    typedef struct token_tree_t<symbol_t> tree_t;
    typedef typename tree_t::node_t node_t;
    typedef typename tree_t::node_ref_t node_ref_t;
    typedef typename tree_t::token_t token_t;

    double evaluate(tree_t const& tree) {
      if (tree_t::no_node_ref != tree.root) {
        return evaluate(tree, tree.node(tree.root));
      } else {
        return 0.0;
      }
    }

    double evaluate(tree_t const& tree, node_ref_t const& ref) {
      return tree.no_node_ref != ref ? evaluate(tree, tree.node(ref)) : 0.0;
    }

    double evaluate(tree_t const& tree, node_t const& node) {
      if (number == node.token.kind) {
        return evaluate_number(node.token);
      } else if (operation == node.token.kind) {
        return evaluate_operation(node.token,
          evaluate(tree, node.left),
          evaluate(tree, node.right));
      }
      return 0.0;
    }

    double evaluate_number(token_t const& token) {
      using namespace std;
      auto stream = basic_stringstream<Symbol>();
      copy(token.symbols.cbegin(), token.symbols.cend(),
        ostream_iterator<Symbol>(stream));
      stream.seekp(0);
      double number = 0.0;
      stream >> number;
      return number;
    }

    double evaluate_operation(token_t const& token, double left, double right) {
      switch (token.symbols.front())
      {
      case '+':
        return left + right;
      case '-':
        return left - right;
      case '*':
        return left * right;
      case '/':
        return left / right;
      default:
        return 0.0;
      }
    }
  };

  template<typename Symbol>
  double evaluate(token_tree_t<Symbol> const& tree) {
    evaluator_t<Symbol> evaluator;
    return evaluator.evaluate(tree);
  }
}
