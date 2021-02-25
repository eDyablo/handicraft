#include "exabeam.hpp"

#include <gmock/gmock.h>

using namespace ::coin::exabeam;
using namespace ::std;
using namespace ::testing;

TEST(exabeam, sumup_non_unique) {
  EXPECT_THAT(sumup_non_unique<int>({}), Eq(0));
  EXPECT_THAT(sumup_non_unique<int>({1}), Eq(0));
  EXPECT_THAT(sumup_non_unique<int>({1, 1}), Eq(2));
  EXPECT_THAT(sumup_non_unique<int>({1, 2, 3, 4, 5, 2, 3, 8}), Eq(10));
}
