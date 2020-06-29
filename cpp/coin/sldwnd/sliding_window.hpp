#pragma once

#include <algorithm>
#include <limits>
#include <string>
#include <valarray>
#include <vector>

namespace coin {
  namespace sliding_window {
    template<typename Element>
    auto find_max_sum_subarray(size_t const subarray_size, std::vector<Element> const& array) {
      size_t subarray_sum = 0;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      for (auto iter = array_begin; iter != array_begin + subarray_size; ++iter) {
        subarray_sum += *iter;
      }
      size_t max_sum = 0;
      for (auto subarray_begin = array_begin, subarray_end = array_begin + subarray_size;
      subarray_end != array_end;
        ++subarray_begin, ++subarray_end) {
        subarray_sum += *subarray_end - *subarray_begin;
        max_sum = std::max(max_sum, subarray_sum);
      }
      return max_sum;
    }

    template<typename Element>
    auto find_smallest_subarray_size(Element const sum, std::vector<Element> const& array) {
      using namespace std;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      size_t min_subarray_size = size(array);
      auto subarray_sum = 0;
      for (auto subarray_begin = array_begin, subarray_end = array_begin;
      subarray_end != array_end; ++subarray_end) {
        subarray_sum += *subarray_end;
        for (; subarray_sum >= sum; ++subarray_begin) {
          subarray_sum -= *subarray_begin;
          min_subarray_size = min<size_t>(min_subarray_size,
            distance(subarray_begin, subarray_end + 1));
        }
      }
      return min_subarray_size;
    }

    template<typename Char>
    auto find_longest_distinct_substring_size(size_t const max_distinct_chars,
    std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<Char>::max() - numeric_limits<Char>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_substring_length = numeric_limits<size_t>::lowest();
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
      substring_end != string_end; ++substring_end) {
        ++char_count[*substring_end];
        for (; size_t(count_if(begin(char_count), end(char_count), above_zero)) >
        max_distinct_chars; ++substring_begin) {
          --char_count[*substring_begin];
        }
        max_substring_length = max<size_t>(max_substring_length,
          distance(substring_begin, substring_end + 1));
      }
      return max_substring_length;
    }

    template<typename Item>
    auto find_max_count_of_types_subarray_size(size_t const types_count, std::vector<Item> array) {
      using namespace std;
      valarray<size_t> item_count(numeric_limits<Item>::max() - numeric_limits<Item>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_subarray_size = numeric_limits<size_t>::lowest();
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      for (auto subarray_begin = array_begin, subarray_end = array_begin;
      subarray_end != array_end; ++subarray_end) {
        ++item_count[*subarray_end];
        for (; size_t(count_if(begin(item_count), end(item_count), above_zero)) > types_count;
        ++subarray_begin) {
          --item_count[*subarray_begin];
        }
        max_subarray_size = max<size_t>(max_subarray_size,
          distance(subarray_begin, subarray_end + 1));
      }
      return max_subarray_size;
    }

    template<typename Char>
    auto find_longest_no_repeating_substring(std::basic_string<Char> const& string) {
      using namespace std;
      using iterator_t = basic_string<Char>::const_iterator;
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      valarray<iterator_t> char_position(string_end,
        numeric_limits<Char>::max() - numeric_limits<Char>::min() + 1);
      auto max_substring_size = numeric_limits<size_t>::lowest();
      for (auto substring_begin = string_begin, substring_end = string_begin;
      substring_end != string_end; ++substring_end) {
        if (char_position[*substring_end] != string_end) {
          substring_begin = char_position[*substring_end] + 1;
        }
        char_position[*substring_end] = substring_end;
        max_substring_size = max<size_t>(max_substring_size,
          distance(substring_begin, substring_end + 1));
      }
      return max_substring_size;
    }

    template<typename Char>
    auto find_longest_same_letter_substring_size(size_t const max_replacements,
    std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<Char>::max() - numeric_limits<Char>::min() + 1u);
      auto max_substring_size = numeric_limits<size_t>::min();
      auto max_repeated_count = numeric_limits<size_t>::min();
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
      substring_end != string_end; ++substring_end) {
        max_repeated_count = max(max_repeated_count, ++char_count[*substring_end]);
        auto const substring_size = size_t(distance(substring_begin, substring_end + 1));
        if (substring_size - max_repeated_count > max_replacements) {
          --char_count[*(substring_begin++)];
        }
        max_substring_size = max<size_t>(max_substring_size,
          distance(substring_begin, substring_end + 1));
      }
      return max_substring_size;
    }

    template<typename Item>
    auto find_longest_same_item_subarray_size(Item const item, size_t max_replacements,
    std::vector<Item> const& array) {
      using namespace std;
      auto max_subarray_size = numeric_limits<size_t>::min();
      size_t item_count = 0;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      for (auto subarray_begin = array_begin, subarray_end = array_begin;
      subarray_end != array_end; ++subarray_end) {
        item_count += (*subarray_end == item);
        auto const subarray_size = distance(subarray_begin, subarray_end + 1);
        if (subarray_size - item_count > max_replacements) {
          item_count -= (*(subarray_begin++) == item);
        }
        max_subarray_size = max<size_t>(max_subarray_size,
          distance(subarray_begin, subarray_end + 1));
      }
      return max_subarray_size;
    }

    template<typename Char>
    auto contains_permutation(std::basic_string<Char> const& pattern,
    std::basic_string<Char> const& string) {
      using namespace std;
      valarray<int> char_count(numeric_limits<char>::max() - numeric_limits<char>::min() + 1);
      for_each(begin(pattern), end(pattern), [&](char c) { ++char_count[c]; });
      size_t expected_matched_char_count = count_if(
        begin(char_count), end(char_count), [](size_t it) { return it > 0; });
      size_t matched_char_count = 0;
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
      substring_end != string_end; ++substring_end) {
        --char_count[*substring_end];
        if (char_count[*substring_end] == 0) {
          ++matched_char_count;
        }
        if (matched_char_count == expected_matched_char_count) {
          return true;
        }
        if (substring_end > string_begin + pattern.size() - 1) {
          if (char_count[*(++substring_begin)] == 0) {
            --matched_char_count;
          }
          ++char_count[*substring_begin];
        }
      }
      return false;
    }

    template<typename Char>
    auto find_anagrams(std::basic_string<Char> const& pattern,
    std::basic_string<Char> const& string) {
      using namespace std;
      valarray<int> char_count(numeric_limits<char>::max() - numeric_limits<char>::min() + 1);
      for_each(begin(pattern), end(pattern), [&](char c) { ++char_count[c]; });
      size_t expected_matched_char_count = count_if(
        begin(char_count), end(char_count), [](size_t it) { return it > 0; });
      size_t matched_char_count = 0;
      vector<size_t> indices;
      auto const pattern_size = size(pattern);
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      auto substring_begin = string_begin;
      auto substring_end = string_begin;
      for (; substring_end != string_end; ++substring_end) {
        --char_count[*substring_end];
        if (char_count[*substring_end] == 0) {
          ++matched_char_count;
        }
        if (matched_char_count == expected_matched_char_count) {
          indices.push_back(distance(string_begin, substring_begin));
        }
        if (substring_end >= string_begin + pattern_size - 1) {
          auto left_char = *(substring_begin++);
          if (char_count[left_char] == 0) {
            --matched_char_count;
          }
          ++char_count[left_char];
        }
      }
      return indices;
    }
  }
}
