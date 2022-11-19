#pragma once

#include <cstddef>
#include <vector>

namespace epc {
  template <typename T, typename N = std::size_t>
  class node_pool_t {
   public:
    using node_ref = N;

    node_pool_t() : free_node(end()) {}

    node_ref allocate(T const& val, node_ref tail) {
      node_ref node = free_node;
      if (is_end(free_node)) {
        node = new_node();
      } else {
        free_node = next(free_node);
      }
      value(node) = val;
      next(node) = tail;
      return node;
    }

    node_ref free(node_ref node) {
      node_ref next_node = next(node);
      next(node) = free_node;
      free_node = node;
      return next_node;
    }

    node_ref end() const { return node_ref{0}; }

    bool is_end(node_ref node) const { return node == end(); }

    T& value(node_ref ref) { return node(ref).value; }

    T const& value(node_ref ref) const { return node(ref).value; }

    node_ref next(node_ref ref) const { return node(ref).next; }

    node_ref& next(node_ref ref) { return node(ref).next; }

    size_t size() const { return pool.size(); }

   private:
    struct node_t {
      T value;
      N next;
    };

    node_t& node(node_ref node) { return pool[node - 1]; }

    node_t const& node(node_ref node) const { return pool[node - 1]; }

    node_ref new_node() {
      pool.push_back(node_t{});
      return node_ref(pool.size());
    }

    std::vector<node_t> pool;

    node_ref free_node;
  };
}  // namespace epc
