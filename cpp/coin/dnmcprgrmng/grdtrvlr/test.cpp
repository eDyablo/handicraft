#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(grdtrvlr, correctness) {
  EXPECT_THAT(grid_travel_ways(0, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(1, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(0, 1), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 2), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 2), Eq(2));
  EXPECT_THAT(grid_travel_ways(3, 2), Eq(3));
  EXPECT_THAT(grid_travel_ways(2, 3), Eq(3));
}

TEST(grdtrvlr, performance) {
  EXPECT_THAT(grid_travel_ways(18, 18), Eq(2'333'606'220));
}
