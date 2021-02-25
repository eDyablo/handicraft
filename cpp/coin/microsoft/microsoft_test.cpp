#include "microsoft.hpp"

#include <gmock/gmock.h>

#include <algorithm>
#include <vector>

using namespace ::coin::microsoft;
using namespace ::std;
using namespace ::testing;

TEST(microsoft, max_sum_of_equal_digits_sum_pair) {
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 71, 17, 42}), Eq(93));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({42, 33, 60}), Eq(102));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 32, 43}), Eq(-1));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({}), Eq(-1));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 71, 17, 42, 33, 80}),
              Eq(151));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({17, 33, 42, 51, 71, 80}),
              Eq(151));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({80, 71, 51, 42, 33, 17}),
              Eq(151));
}

TEST(microsoft, max_sum_of_equal_digits_sum_pair_performance) {
  vector<int> numbers(200'000);
  generate(begin(numbers), end(numbers), []() -> int {
    static int counter = 1'000'000'000;
    return counter--;
  });
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair(numbers), Not(Eq(-1)));
}
