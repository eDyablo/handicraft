#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::mzn;

TEST(ctfrnks, correctness) {
  EXPECT_THAT(rankup_count(3, {100, 50, 50, 25}), Eq(3));
  EXPECT_THAT(rankup_count(4, {2, 2, 3, 4, 5}), Eq(5));
}
