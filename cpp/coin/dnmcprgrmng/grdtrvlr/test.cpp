#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(grdtrvlr_brtfrc, correctness) {
  using namespace brtfrc;
  EXPECT_THAT(grid_travel_ways(0, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(1, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(0, 1), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 2), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 2), Eq(2));
  EXPECT_THAT(grid_travel_ways(3, 2), Eq(3));
  EXPECT_THAT(grid_travel_ways(2, 3), Eq(3));
  EXPECT_THAT(grid_travel_ways(3, 3), Eq(6));
}

TEST(grdtrvlr_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(grid_travel_ways(0, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(1, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(0, 1), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 2), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 2), Eq(2));
  EXPECT_THAT(grid_travel_ways(3, 2), Eq(3));
  EXPECT_THAT(grid_travel_ways(2, 3), Eq(3));
  EXPECT_THAT(grid_travel_ways(3, 3), Eq(6));
}

TEST(grdtrvlr_mztn, performance) {
  using namespace mztn;
  EXPECT_THAT(grid_travel_ways(18, 18), Eq(2'333'606'220));
}

TEST(grdtrvlr_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(grid_travel_ways(0, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(1, 0), Eq(0));
  EXPECT_THAT(grid_travel_ways(0, 1), Eq(0));
  EXPECT_THAT(grid_travel_ways(1, 2), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 1), Eq(1));
  EXPECT_THAT(grid_travel_ways(2, 2), Eq(2));
  EXPECT_THAT(grid_travel_ways(3, 2), Eq(3));
  EXPECT_THAT(grid_travel_ways(2, 3), Eq(3));
  EXPECT_THAT(grid_travel_ways(3, 3), Eq(6));
}

TEST(grdtrvlr_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(grid_travel_ways(18, 18), Eq(2'333'606'220));
}
