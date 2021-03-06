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

TEST(two_pointers, find_triplets) {
  vector<int> numbers;

  numbers = {-3, 0, 1, 2, -1, 1, -2};
  EXPECT_THAT(find_triplets(numbers),
              ElementsAre(array{-3, 1, 2}, array{-2, 0, 2}, array{-2, 1, 1},
                          array{-1, 0, 1}));

  numbers = {-5, 2, -1, -2, 3};
  EXPECT_THAT(find_triplets(numbers),
              ElementsAre(array{-5, 2, 3}, array{-2, -1, 3}));
}

TEST(two_pointers, find_triplet_sum_close_to_target) {
  EXPECT_THAT(find_triplet_sum_close_to_target(2, {-2, 0, 1, 2}), Eq(1));
  EXPECT_THAT(find_triplet_sum_close_to_target(1, {-3, -1, 1, 2}), Eq(0));
  EXPECT_THAT(find_triplet_sum_close_to_target(100, {1, 0, 1, 1}), Eq(3));
}

TEST(two_pointers, count_triplets_with_smaller_sum) {
  EXPECT_THAT(count_triplets_with_smaller_sum(3, {-1, 0, 2, 3}), Eq(2));
  EXPECT_THAT(count_triplets_with_smaller_sum(5, {-1, 4, 2, 1, 3}), Eq(4));
}

TEST(two_pointers, find_triplets_with_smaller_sum) {
  EXPECT_THAT(find_triplets_with_smaller_sum(3, {-1, 0, 2, 3}),
              ElementsAre(array{-1, 0, 2}, array{-1, 0, 3}));
  EXPECT_THAT(find_triplets_with_smaller_sum(5, {-1, 4, 2, 1, 3}),
              ElementsAre(array{-1, 1, 2}, array{-1, 1, 3}, array{-1, 1, 4},
                          array{-1, 2, 3}));
}

TEST(two_pointers, find_subarrays_with_smaller_product) {
  EXPECT_THAT(find_subarrays_with_smaller_product(30, {2, 5, 3, 10}),
              ElementsAre(vector{2}, vector{5}, vector{2, 5}, vector{3},
                          vector{5, 3}, vector{10}));
  EXPECT_THAT(find_subarrays_with_smaller_product(50, {8, 2, 6, 5}),
              ElementsAre(vector{8}, vector{2}, vector{8, 2}, vector{6},
                          vector{2, 6}, vector{5}, vector{6, 5}));
}

TEST(two_pointers, dutch_flag_sort) {
  vector<uint16_t> objects;

  objects = {1, 0, 2, 1, 0};
  dutch_flag_sort(uint16_t(0), uint16_t(2), objects);
  EXPECT_THAT(objects, ElementsAre(0, 0, 1, 1, 2));

  objects = {2, 2, 0, 1, 2, 0};
  dutch_flag_sort(uint16_t(0), uint16_t(2), objects);
  EXPECT_THAT(objects, ElementsAre(0, 0, 1, 2, 2, 2));
}

TEST(two_pointers, find_quardruplets_with_taget_sum) {
  EXPECT_THAT(find_quardruplets_with_taget_sum(1, {4, 1, 2, -1, 1, -3}),
              ElementsAre(array{-3, -1, 1, 4}, array{-3, 1, 1, 2}));
  EXPECT_THAT(find_quardruplets_with_taget_sum(2, {2, 0, -1, 1, -2, 2}),
              ElementsAre(array{-2, 0, 2, 2}, array{-1, 0, 1, 2}));
}

TEST(two_pointers, compare_strings_with_backspaces) {
  EXPECT_TRUE(compare_strings_with_backspaces<char>("xy#z", "xzz#"));
  EXPECT_FALSE(compare_strings_with_backspaces<char>("xy#z", "xyz#"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("xp#", "xyz##"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("xywrrmp", "xywrrmu#p"));
  EXPECT_FALSE(compare_strings_with_backspaces<char>("ab", "b"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("#", "#"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("a#", "a#"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("a##", "a##"));
  EXPECT_TRUE(compare_strings_with_backspaces<char>("a#", "a##"));
}
