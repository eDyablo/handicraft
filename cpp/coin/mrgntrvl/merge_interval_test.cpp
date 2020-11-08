#include "merge_interval.hpp"

#include <gmock/gmock.h>

using namespace ::coin;
using namespace ::testing;

TEST(merge_interval, returns_empty_vector_for_empty_vector) {
  EXPECT_THAT(merge(interval_vector_t{}),
      ElementsAreArray(interval_vector_t{}));
}

TEST(merge_interval, returns_single_element_vector_for_single_element_vector) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}}),
      ElementsAreArray(interval_vector_t{{0, 1}}));
}

TEST(merge_interval, returns_single_element_vector_for_two_joint_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}, {1, 2}}),
      ElementsAreArray(interval_vector_t{{0, 2}}));
}

TEST(merge_interval, returns_two_elements_vector_for_two_disjoint_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}, {2, 3}}),
      ElementsAreArray(interval_vector_t{{0, 1}, {2, 3}}));
}

TEST(merge_interval, returns_correctly_merged_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {15, 18}, {18, 21}}),
      ElementsAreArray(interval_vector_t{{1, 6}, {8, 10}, {15, 21}}));
  EXPECT_THAT(merge(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {9, 18}, {18, 21}, {5, 11}}),
      ElementsAreArray(interval_vector_t{{1, 21}}));
}
