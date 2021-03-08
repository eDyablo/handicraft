#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::mzn;
using namespace ::testing;

TEST(ldcrg, correctness) {
  EXPECT_THAT(maximum_shipped_items({3, 1, 2}, {1, 2, 3}, 4), Eq(9));
}
