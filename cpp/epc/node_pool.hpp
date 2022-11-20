#pragma once

#include <cstddef>
#include <vector>

namespace epc {
  template <typename T, typename N = std::size_t>
  class node_pool_t {
   public:
    using value_t = T;
    using node_ref_t = N;

    node_pool_t() : free_node(end()) {}

    node_ref_t allocate(value_t const& val, node_ref_t tail) {
      node_ref_t node = free_node;
      if (is_end(free_node)) {
        node = new_node();
      } else {
        free_node = next(free_node);
      }
      value(node) = val;
      next(node) = tail;
      return node;
    }

    node_ref_t free(node_ref_t node) {
      node_ref_t next_node = next(node);
      next(node) = free_node;
      free_node = node;
      return next_node;
    }

    node_ref_t end() const { return node_ref_t{0}; }

    bool is_end(node_ref_t node) const { return node == end(); }

    value_t& value(node_ref_t ref) { return node(ref).value; }

    value_t const& value(node_ref_t ref) const { return node(ref).value; }

    node_ref_t next(node_ref_t ref) const { return node(ref).next; }

    node_ref_t& next(node_ref_t ref) { return node(ref).next; }

    size_t size() const { return pool.size(); }

   private:
    struct node_t {
      T value;
      N next;
    };

    node_t& node(node_ref_t node) { return pool[node - 1]; }

    node_t const& node(node_ref_t node) const { return pool[node - 1]; }

    node_ref_t new_node() {
      pool.push_back(node_t{});
      return node_ref_t(pool.size());
    }

    std::vector<node_t> pool;

    node_ref_t free_node;
  };
}  // namespace epc
