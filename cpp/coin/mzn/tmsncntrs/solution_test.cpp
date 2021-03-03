#include "solution.hpp"

#include <gmock/gmock.h>

using namespace ::std;
using namespace ::testing;
using namespace ::coin::mzn;

TEST(mzn, count_inventory) {
  EXPECT_THAT(count_inventory("|**|*|*", {1, 1}, {5, 6}), ElementsAre(2, 3));
  EXPECT_THAT(count_inventory("|**|*|*", {1}, {7}), ElementsAre(3));
  EXPECT_THAT(count_inventory("|**|*|*|", {1}, {8}), ElementsAre(4));
}
