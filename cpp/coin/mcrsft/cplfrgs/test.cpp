#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::mcrsft;

TEST(cplfrgs, correctness) {
  EXPECT_THAT(get_longest_distance({2, 6, 8, 5}), Eq(3));
  EXPECT_THAT(get_longest_distance({1, 5, 5, 2, 6}), Eq(4));
}
