#include <iostream>

#include "sliding_window.hpp"

void test(size_t expected, size_t actual) {
  using namespace std;
  if (actual != expected) {
    cout << "expected: " << expected << endl
      << "actual: " << actual << endl << endl;
  }
}

int main() {
  using namespace std;
  using namespace coin::sliding_window;
  test(9u, find_max_sum_subarray<int8_t>(3u, {2, 1, 5, 1, 3, 2}));
  test(7u, find_max_sum_subarray<int8_t>(2u, {2, 3, 4, 1, 5}));
  test(2u, find_smallest_subarray_size<int8_t>(7, {2, 1, 5, 2, 3, 2}));
  test(1u, find_smallest_subarray_size<int8_t>(7, {2, 1, 5, 2, 8}));
  test(3u, find_smallest_subarray_size<int8_t>(8, {3, 4, 1, 1, 6}));
  test(4u, find_longest_distinct_substring_size<char>(2u, "araaci"));
  test(2u, find_longest_distinct_substring_size<char>(1u, "araaci"));
  test(5u, find_longest_distinct_substring_size<char>(3u, "cbbebi"));
  test(3u, find_max_count_of_types_subarray_size<char>(2u, {'A', 'B', 'C', 'A', 'C'}));
  test(5u, find_max_count_of_types_subarray_size<char>(2u, {'A', 'B', 'C', 'B', 'B', 'C'}));
  test(3u, find_longest_no_repeating_substring<char>("aabccbb"));
  test(2u, find_longest_no_repeating_substring<char>("abbbb"));
  test(3u, find_longest_no_repeating_substring<char>("abccde"));
  test(5u, find_longest_same_letter_substring_size<char>(2u, "aabccbb"));
  test(4u, find_longest_same_letter_substring_size<char>(1u, "abbcb"));
  test(3u, find_longest_same_letter_substring_size<char>(1u, "abccde"));
  test(6u, find_longest_same_item_subarray_size<uint8_t>(1u, 2u, {0,1,1,0,0,0,1,1,0,1,1}));
  test(9u, find_longest_same_item_subarray_size<uint8_t>(1u, 3u, {0,1,0,0,1,1,0,1,1,0,0,1,1}));
  return 0;
}
