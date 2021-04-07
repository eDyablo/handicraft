#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::prstrg;

// 7 -> 22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
TEST(cltz, correctness) {
  EXPECT_THAT(collatz(1), Eq(0));
  EXPECT_THAT(collatz(2), Eq(1));
  EXPECT_THAT(collatz(4), Eq(2));
  EXPECT_THAT(collatz(8), Eq(3));
  EXPECT_THAT(collatz(26), Eq(10));
  EXPECT_THAT(collatz(7), Eq(16));
}
