#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::mzn;
using namespace ::testing;

TEST(ldcrg, correctness) {
  EXPECT_THAT(maximum_shipped_items({3, 1, 2}, {1, 2, 3}, 4), Eq(9));
  EXPECT_THAT(maximum_shipped_items({1, 2, 3}, {3, 2, 1}, 3), Eq(7));
  EXPECT_THAT(maximum_shipped_items({1, 2, 3}, {3, 2, 1}, 10), Eq(10));
}
