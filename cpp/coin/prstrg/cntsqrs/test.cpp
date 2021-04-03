#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::prstrg;

TEST(cntsqrs, distance_correctness) {
  EXPECT_THAT(distance(point_t{0, 0}, point_t{0, 1}), Eq(1));
  EXPECT_THAT(distance(point_t{1, 0}, point_t{0, 0}), Eq(1));
  EXPECT_NEAR(distance(point_t{0, 0}, point_t{1, 1}), 1.41, 0.01);
}
