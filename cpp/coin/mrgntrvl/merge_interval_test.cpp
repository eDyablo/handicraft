#include "merge_interval.hpp"

#include <gmock/gmock.h>

using namespace ::coin;
using namespace ::testing;

TEST(merge, returns_empty_vector_for_empty_vector) {
  EXPECT_THAT(merge(interval_vector_t{}),
      ElementsAreArray(interval_vector_t{}));
}

TEST(merge2, returns_empty_vector_for_empty_vector) {
  EXPECT_THAT(merge2(interval_vector_t{}),
      ElementsAreArray(interval_vector_t{}));
}

TEST(merge, returns_single_element_vector_for_single_element_vector) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}}),
      ElementsAreArray(interval_vector_t{{0, 1}}));
}

TEST(merge2, returns_single_element_vector_for_single_element_vector) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}}),
      ElementsAreArray(interval_vector_t{{0, 1}}));
}

TEST(merge, returns_single_element_vector_for_two_joint_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}, {1, 2}}),
      ElementsAreArray(interval_vector_t{{0, 2}}));
}

TEST(merge2, returns_single_element_vector_for_two_joint_intervals) {
  EXPECT_THAT(merge2(interval_vector_t{{0, 1}, {1, 2}}),
      ElementsAreArray(interval_vector_t{{0, 2}}));
}

TEST(merge, returns_two_elements_vector_for_two_disjoint_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{0, 1}, {2, 3}}),
      ElementsAreArray(interval_vector_t{{0, 1}, {2, 3}}));
}

TEST(merge2, returns_two_elements_vector_for_two_disjoint_intervals) {
  EXPECT_THAT(merge2(interval_vector_t{{0, 1}, {2, 3}}),
      ElementsAreArray(interval_vector_t{{0, 1}, {2, 3}}));
}

TEST(merge, returns_correctly_merged_intervals) {
  EXPECT_THAT(merge(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {15, 18}, {18, 21}}),
      ElementsAreArray(interval_vector_t{{1, 6}, {8, 10}, {15, 21}}));
  EXPECT_THAT(merge(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {9, 18}, {18, 21}, {5, 11}}),
      ElementsAreArray(interval_vector_t{{1, 21}}));
}

TEST(merge2, returns_correctly_merged_intervals) {
  EXPECT_THAT(merge2(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {15, 18}, {18, 21}}),
      ElementsAreArray(interval_vector_t{{1, 6}, {8, 10}, {15, 21}}));
  EXPECT_THAT(merge2(interval_vector_t{{2, 6}, {8, 10}, {1, 3}, {9, 18}, {18, 21}, {5, 11}}),
      ElementsAreArray(interval_vector_t{{1, 21}}));
  EXPECT_THAT(merge2(interval_vector_t{{-3, 0}, {0, 3}}),
      ElementsAreArray(interval_vector_t{{-3, 3}}));
  EXPECT_THAT(merge2(interval_vector_t{{-9, -7}, {-8, -5}}),
    ElementsAreArray(interval_vector_t{{-9, -5}}));
  EXPECT_THAT(merge2(interval_vector_t{{-1, 1}, {-2, 2}, {-4, 4}, {-7, 7}}),
    ElementsAreArray(interval_vector_t{{-7, 7}}));
  EXPECT_THAT(merge2(interval_vector_t{{-7, 7}, {-2, 2}, {-4, 4}, {-1, 1}}),
    ElementsAreArray(interval_vector_t{{-7, 7}}));
  EXPECT_THAT(merge2(interval_vector_t{{10000, 10003}, {10002, 10005}}),
    ElementsAreArray(interval_vector_t{{10000, 10005}}));
  EXPECT_THAT(merge2(interval_vector_t{{-10003, -10000}, {-10005, -10002}}),
    ElementsAreArray(interval_vector_t{{-10005, -10000}}));
}
