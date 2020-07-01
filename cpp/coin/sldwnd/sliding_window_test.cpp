#include <gmock/gmock.h>

#include "sliding_window.hpp"

TEST(sliding_window, find_max_sum_subarray) {
  using namespace coin::sliding_window;
  EXPECT_EQ(9u, find_max_sum_subarray<int8_t>(3u, {2, 1, 5, 1, 3, 2}));
  EXPECT_EQ(7u, find_max_sum_subarray<int8_t>(2u, {2, 3, 4, 1, 5}));
}

TEST(sliding_window, find_smallest_subarray_size) {
  using namespace coin::sliding_window;
  EXPECT_EQ(2u, find_smallest_subarray_size<int8_t>(7, {2, 1, 5, 2, 3, 2}));
  EXPECT_EQ(1u, find_smallest_subarray_size<int8_t>(7, {2, 1, 5, 2, 8}));
  EXPECT_EQ(3u, find_smallest_subarray_size<int8_t>(8, {3, 4, 1, 1, 6}));
}

TEST(sliding_window, find_longest_distinct_substring_size) {
  using namespace coin::sliding_window;
  EXPECT_EQ(4u, find_longest_distinct_substring_size<char>(2u, "araaci"));
  EXPECT_EQ(2u, find_longest_distinct_substring_size<char>(1u, "araaci"));
  EXPECT_EQ(5u, find_longest_distinct_substring_size<char>(3u, "cbbebi"));
}

TEST(sliding_window, find_max_count_of_types_subarray_size) {
  using namespace coin::sliding_window;
  EXPECT_EQ(3u, find_max_count_of_types_subarray_size<char>(
                    2u, {'A', 'B', 'C', 'A', 'C'}));
  EXPECT_EQ(5u, find_max_count_of_types_subarray_size<char>(
                    2u, {'A', 'B', 'C', 'B', 'B', 'C'}));
}

TEST(sliding_window, find_longest_no_repeating_substring) {
  using namespace coin::sliding_window;
  EXPECT_EQ(3u, find_longest_no_repeating_substring<char>("aabccbb"));
  EXPECT_EQ(2u, find_longest_no_repeating_substring<char>("abbbb"));
  EXPECT_EQ(3u, find_longest_no_repeating_substring<char>("abccde"));
}

TEST(sliding_window, find_longest_same_letter_substring_size) {
  using namespace coin::sliding_window;
  EXPECT_EQ(5u, find_longest_same_letter_substring_size<char>(2u, "aabccbb"));
  EXPECT_EQ(4u, find_longest_same_letter_substring_size<char>(1u, "abbcb"));
  EXPECT_EQ(3u, find_longest_same_letter_substring_size<char>(1u, "abccde"));
}

TEST(sliding_window, find_longest_same_item_subarray_size) {
  using namespace coin::sliding_window;
  EXPECT_EQ(6u, find_longest_same_item_subarray_size<uint8_t>(
                    1u, 2u, {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}));
  EXPECT_EQ(9u, find_longest_same_item_subarray_size<uint8_t>(
                    1u, 3u, {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}));
}

TEST(sliding_window, contains_permutation) {
  using namespace coin::sliding_window;
  EXPECT_TRUE(contains_permutation<char>("abc", "oidbcaf"));
  EXPECT_FALSE(contains_permutation<char>("dc", "odicf"));
  EXPECT_TRUE(contains_permutation<char>("bcdyabcdx", "bcdxabcdy"));
  EXPECT_TRUE(contains_permutation<char>("abc", "aaacb"));
}

TEST(sliding_window, find_anagrams) {
  using namespace coin::sliding_window;
  using namespace ::testing;
  EXPECT_THAT(find_anagrams<char>("ab", "ab"), ElementsAre(0));
  EXPECT_THAT(find_anagrams<char>("ab", "abab"), ElementsAre(0, 1, 2));
  EXPECT_THAT(find_anagrams<char>("ab", "abcabcab"), ElementsAre(0, 3, 6));
  EXPECT_THAT(find_anagrams<char>("ab", "cabcabcab"), ElementsAre(1, 4, 7));
  EXPECT_THAT(find_anagrams<char>("pq", "ppqp"), ElementsAre(1, 2));
  EXPECT_THAT(find_anagrams<char>("abc", "abbcabc"), ElementsAre(2, 3, 4));
}
