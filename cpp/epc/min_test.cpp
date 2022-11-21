#include "min.hpp"

#include <gmock/gmock.h>

#include <functional>

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

    TEST(Min, FirstAndSecondMin) {
      int sequence[] = {9, 13, 7, 124, 32, 1};
      auto const result = first_and_second_min(
          sequence, sequence + sizeof(sequence) / sizeof(int),
          std::less<int>());
      EXPECT_THAT(*result.first, Eq(1));
      EXPECT_THAT(*result.second, Eq(7));
    }
  }  // namespace
}  // namespace epc
