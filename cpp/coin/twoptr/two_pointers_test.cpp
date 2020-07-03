#include "two_pointers.hpp"

#include <gmock/gmock.h>

using namespace ::coin::two_pointers;
using namespace ::testing;
using ::testing::Pair;
using namespace ::std;

TEST(two_pointers, find_target_sum_pair) {
  EXPECT_THAT(find_target_sum_pair<int>(6, {1, 2, 3, 4, 6}), Pair(1, 3));
  EXPECT_THAT(find_target_sum_pair<int>(11, {2, 5, 9, 11}), Pair(0, 2));
}

TEST(two_pointers, remove_duplicates) {
  vector<int> numbers;
  
  numbers = {2, 3, 3, 3, 6, 9, 9};
  EXPECT_THAT(remove_duplicates(numbers), Eq(4));
  EXPECT_THAT(numbers, ElementsAre(2, 3, 6, 9, 6, 9, 9));

  numbers = {2, 2, 2, 11};
  EXPECT_THAT(remove_duplicates(numbers), Eq(2));
  EXPECT_THAT(numbers, ElementsAre(2, 11, 2, 11));
}

TEST(two_pointers, remove_all_inclusions) {
  vector<int> numbers;
  
  numbers = {3, 2, 3, 6, 3, 10, 9, 3};
  EXPECT_THAT(remove_all_inclusions(3, numbers), Eq(4));
  EXPECT_THAT(numbers, ElementsAre(2, 6, 10, 9, 3, 10, 9, 3));

  numbers = {2, 11, 2, 2, 1};
  EXPECT_THAT(remove_all_inclusions(2, numbers), Eq(2));
  EXPECT_THAT(numbers, ElementsAre(11, 1, 2, 2, 1));
}

TEST(two_pointers, make_squares) {
  EXPECT_THAT(make_squares<int>({-2, -1, 0, 2, 3}), ElementsAre(0, 1, 4, 4, 9));
  EXPECT_THAT(make_squares<int>({-3, -1, 0, 1, 2}), ElementsAre(0, 1, 1, 4, 9));
}
