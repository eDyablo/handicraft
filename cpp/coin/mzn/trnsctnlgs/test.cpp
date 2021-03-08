#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::mzn;

TEST(trnsctnlgs, correctness) {
  EXPECT_THAT(find_excessive_users(
                  2, {"88 99 200", "88 99 300", "99 32 100", "12 12 15"}),
              ElementsAre(88, 99));
}
