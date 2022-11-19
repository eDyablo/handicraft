#pragma once

#include <utility>

#include "binary_counter.hpp"
#include "node_pool.hpp"

namespace epc {
  template <typename T, typename N, typename Compare>
  auto min_value_node(node_pool_t<T, N> const& pool,
                      typename node_pool_t<T, N>::node_ref head,
                      Compare compare) {
    auto min = head;
    for (; head != pool.end(); head = pool.next(head)) {
      if (compare(pool.value(head), pool.value(min))) {
        min = head;
      }
    }
    return min;
  }
}  // namespace epc
