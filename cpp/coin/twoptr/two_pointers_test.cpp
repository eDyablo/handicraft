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
  vector<int> numbers{2, 3, 3, 3, 6, 9, 9};
  EXPECT_THAT(remove_duplicates(numbers), Eq(4));
  EXPECT_THAT(numbers, ElementsAre(2, 3, 6, 9, 6, 9, 9));
}
