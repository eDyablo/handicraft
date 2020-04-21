#pragma once

#include "token.hpp"
#include <limits>
#include <ostream>
#include <vector>

namespace calc {
  template<typename Symbol>
  struct token_tree_node_t {
    typedef Symbol symbol_t;
    typedef struct token_t<symbol_t> token_t;
    typedef token_tree_node_t node_t;
    typedef size_t node_ref_t;

    static const node_ref_t no_ref;

    token_t token;
    node_ref_t left;
    node_ref_t right;

    token_tree_node_t(token_t const& token):
    token(token),
    left(no_ref),
    right(no_ref) {
    }

    template <typename>
    friend std::ostream& operator<<(std::ostream& stream, node_t const& node);
  };

  template<typename Symbol>
  const typename token_tree_node_t<Symbol>::node_ref_t token_tree_node_t<Symbol>::no_ref =
    std::numeric_limits<token_tree_node_t<Symbol>::node_ref_t>::max();

  template <typename Symbol>
  std::ostream& operator<<(std::ostream& stream, token_tree_node_t<Symbol> const& node) {
    stream << node.token;
    if (node.left != node.no_ref) {
      stream << ",l:" << node.left;
    }
    if (node.right != node.no_ref) {
      stream << ",r:" << node.right;
    }
    return stream;
  }

  template<typename Symbol>
  struct token_tree_t {
    typedef Symbol symbol_t;
    typedef struct token_t<symbol_t> token_t;
    typedef struct token_tree_node_t<symbol_t> node_t;
    typedef std::vector<node_t> node_vector_t;
    typedef typename node_t::node_ref_t node_ref_t;

    static const node_ref_t no_node_ref;

    node_ref_t root;
    node_vector_t nodes;

    token_tree_t():
    root(no_node_ref) {
    }

    template <typename>
    friend std::ostream& operator<<(std::ostream& stream, token_tree_t const& tree);

    node_ref_t add(node_t const& node) {
      nodes.push_back(node);
      return last_node_ref();
    }

    node_ref_t last_node_ref() const {
      return nodes.empty() ? no_node_ref : nodes.size() - 1;
    }

    node_t& node(node_ref_t const& ref) {
      return nodes.at(ref);
    }

    node_t& last_node() {
      return nodes.back();
    }
  };

  template<typename Symbol>
  const typename token_tree_t<Symbol>::node_ref_t token_tree_t<Symbol>::no_node_ref =
    token_tree_node_t<Symbol>::no_ref;

  template<typename Symbol>
  std::ostream& operator<<(std::ostream& stream, token_tree_t<Symbol> const& tree) {
    using namespace std;
    typedef typename token_tree_t<Symbol>::node_t node_t;
    stream << "root:" << tree.root << " ";
    copy(tree.nodes.cbegin(), tree.nodes.cend(), ostream_iterator<node_t>(stream, " "));
    return stream;
  }
}
