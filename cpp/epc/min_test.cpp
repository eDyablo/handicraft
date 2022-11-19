#include "min.hpp"

#include <gmock/gmock.h>

namespace epc {
  namespace {
    using ::testing::Eq;

    TEST(Min, MinValueNode) {
      node_pool_t<int> pool;
      auto const compare = std::less<int>();

      auto min = min_value_node(pool, pool.end(), compare);
      ASSERT_THAT(min, Eq(pool.end()));

      auto const one_element_list = pool.allocate(1, pool.end());
      min = min_value_node(pool, one_element_list, compare);
      ASSERT_THAT(min, Eq(one_element_list));

      auto const first = pool.allocate(1, pool.end());
      auto head = pool.allocate(2, first);
      head = pool.allocate(3, head);
      min = min_value_node(pool, head, compare);
      ASSERT_THAT(min, Eq(first));
    }
  }  // namespace
}  // namespace epc
