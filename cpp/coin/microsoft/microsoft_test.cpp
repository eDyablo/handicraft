#include "microsoft.hpp"

#include <gmock/gmock.h>

using namespace ::coin::microsoft;
using namespace ::std;
using namespace ::testing;

TEST(microsoft, max_sum_of_equal_digits_sum_pair) {
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 71, 17, 42}), Eq(93));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({42, 33, 60}), Eq(102));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 32, 43}), Eq(-1));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({}), Eq(-1));
}
