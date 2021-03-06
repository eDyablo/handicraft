#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::std;
using namespace ::testing;
using namespace ::coin::mzn;

TEST(tmsncntrs, correctness) {
  EXPECT_THAT(count_inventory("|**|*|*", {1, 1}, {5, 6}), ElementsAre(2, 3));
  EXPECT_THAT(count_inventory("|**|*|*", {1}, {7}), ElementsAre(3));
  EXPECT_THAT(count_inventory("|**|*|*|", {1}, {8}), ElementsAre(4));
  EXPECT_THAT(count_inventory("", {}, {}), ElementsAre());
  EXPECT_THAT(count_inventory("", {1}, {2}), ElementsAre());
  EXPECT_THAT(count_inventory("*", {1}, {2}), ElementsAre());
  EXPECT_THAT(count_inventory("|*|", {1}, {3}), ElementsAre(1));
  EXPECT_THAT(count_inventory("|*", {1}, {3}), ElementsAre());
  EXPECT_THAT(count_inventory("|***|", {1, 1, 1, 1, 1}, {1, 2, 3, 4, 5}),
              ElementsAre(3));
  EXPECT_THAT(count_inventory("|***|", {2, 2, 2}, {2, 3, 4}), ElementsAre());
  EXPECT_THAT(count_inventory("***", {1, 1}, {2, 3}), ElementsAre());
}
