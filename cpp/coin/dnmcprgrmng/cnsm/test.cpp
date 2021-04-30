#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(cnsm, correctness) {
  EXPECT_THAT(can_sum(0, {}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 3}), Eq(true));
  EXPECT_THAT(can_sum(7, {5, 3, 4, 7}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 4}), Eq(false));
  EXPECT_THAT(can_sum(8, {2, 3, 5}), Eq(true));
}

TEST(cnsm, performance) {
  EXPECT_THAT(can_sum(300, {7, 14}), Eq(false));
}
