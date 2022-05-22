#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::mzn;
using namespace ::std;
using namespace ::testing;

TEST(cntdcrsngrtngs, correctness) {
  EXPECT_THAT(count_decreasing_ratings(vector<int>()), Eq(0));
  EXPECT_THAT(count_decreasing_ratings({1}), Eq(1));
  EXPECT_THAT(count_decreasing_ratings({1, 2}), Eq(2));
  EXPECT_THAT(count_decreasing_ratings({1, 2, 3}), Eq(3));
  EXPECT_THAT(count_decreasing_ratings({2, 2}), Eq(2));
  EXPECT_THAT(count_decreasing_ratings({3, 3, 3}), Eq(3));
  EXPECT_THAT(count_decreasing_ratings({2, 1}), Eq(3));
  EXPECT_THAT(count_decreasing_ratings({3, 2, 1}), Eq(6));
  EXPECT_THAT(count_decreasing_ratings({2, 1, 3}), Eq(4));
  EXPECT_THAT(count_decreasing_ratings({4, 3, 5, 4, 3}), Eq(9));
}
