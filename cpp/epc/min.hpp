#pragma once

#include <type_traits>
#include <utility>

#include "binary_counter.hpp"
#include "node_pool.hpp"

namespace epc {
  template <typename T, typename N, typename Compare>
  auto min_value_node(node_pool_t<T, N> const& pool,
                      typename node_pool_t<T, N>::node_ref_t head,
                      Compare compare) {
    auto min = head;
    for (; head != pool.end(); head = pool.next(head)) {
      if (compare(pool.value(head), pool.value(min))) {
        min = head;
      }
    }
    return min;
  }

  template <typename Compare>
  struct compare_deref_t {
    compare_deref_t(Compare compare) : compare(compare) {}

    template <typename I>
    bool operator()(I first, I second) const {
      return compare(*first, *second);
    }

   private:
    Compare compare;
  };

  template <typename I, typename N>
  void free_list(node_pool_t<I, N>& pool,
                 typename node_pool_t<I, N>::node_ref_t head) {
    while (!pool.is_end(head)) {
      head = pool.free(head);
    }
  }

  template <typename I, typename N>
  auto combine(std::pair<I, typename node_pool_t<I, N>::node_ref_t> const& x,
               std::pair<I, typename node_pool_t<I, N>::node_ref_t> const& y,
               node_pool_t<I, N>& pool) {
    free_list(pool, y.second);
    auto const head = pool.allocate(y.first, x.second);
    return std::make_pair(x.first, head);
  }

  template <typename I, typename N, typename Compare>
  struct combine_lists_t {
    using node_pool_t = node_pool_t<I, N>;
    using argument_t = std::pair<I, typename node_pool_t::node_ref_t>;

    combine_lists_t(node_pool_t& pool, Compare compare)
        : pool(&pool), compare(compare) {}

    argument_t operator()(argument_t const& x, argument_t const& y) const {
      return compare(y.first, x.first) ? combine(y, x, *pool)
                                       : combine(x, y, *pool);
    }

   private:
    Compare compare;
    mutable node_pool_t* pool;
  };

  template <typename I, typename Compare>
  std::pair<I, I> first_and_second_min(I first, I last, Compare compare) {
    node_pool_t<I> pool;
    compare_deref_t<decltype(compare)> compare_deref(compare);
    combine_lists_t combine_lists(pool, compare_deref);
    auto const zero = std::make_pair(last, pool.end());
    binary_counter_t<std::remove_const_t<decltype(zero)>,
                     decltype(combine_lists)>
        counter(zero, combine_lists);

    for (; first != last; ++first) {
      counter.add(std::make_pair(first, pool.end()));
    }
    auto const min = counter.reduce();
    auto const second_min =
        pool.is_end(min.second)
            ? last
            : pool.value(min_value_node(pool, min.second, compare_deref));
    return std::make_pair(min.first, second_min);
  }
}  // namespace epc
