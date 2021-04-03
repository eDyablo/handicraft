#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::prstrg;

TEST(cntsqrs, distance_correctness) {
  EXPECT_THAT(distance(point_t{0, 0}, point_t{0, 1}), Eq(1));
  EXPECT_THAT(distance(point_t{1, 0}, point_t{0, 0}), Eq(1));
  EXPECT_NEAR(distance(point_t{0, 0}, point_t{1, 1}), 1.41, 0.01);
}

TEST(cntsqrs, is_square_correctness) {
  EXPECT_THAT(is_square(point_vec_t{{0, 0}, {0, 2}, {2, 0}, {2, 2}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{0, 1}, {2, 1}, {1, 0}, {1, 2}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{1, 0}, {0, 2}, {2, 3}, {3, 1}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{1, 0}, {3, 4}, {0, 3}, {4, 1}}), Eq(true));
}
