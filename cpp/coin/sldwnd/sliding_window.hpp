#pragma once

#include <algorithm>
#include <limits>
#include <string>
#include <valarray>
#include <vector>

namespace coin {
  namespace sliding_window {
    template<typename Element>
    auto find_max_sum_subarray(size_t subarray_size, std::vector<Element> const& array) {
      size_t subarray_sum = 0;
      auto const begin = array.begin();
      auto const end = array.end();
      for (auto iter = begin; iter != begin + subarray_size; ++iter) {
        subarray_sum += *iter;
      }
      size_t max_sum = 0;
      for (auto subarray_begin = begin, subarray_end = begin + subarray_size; subarray_end != end;
        ++subarray_begin, ++subarray_end) {
        subarray_sum += *subarray_end - *subarray_begin;
        max_sum = std::max(max_sum, subarray_sum);
      }
      return max_sum;
    }

    template<typename Element>
    auto find_min_subarray(Element min_sum, std::vector<Element> const& array) {
      using namespace std;
      auto const begin = array.begin();
      auto const end = array.end();
      size_t min_subarray_size = array.size();
      auto subarray_sum = 0;
      for (auto subarray_begin = begin, subarray_end = begin; subarray_end != end; ++subarray_end) {
        subarray_sum += *subarray_end;
        for (; subarray_sum >= min_sum; ++subarray_begin) {
          subarray_sum -= *subarray_begin;
          min_subarray_size = min(min_subarray_size,
            size_t(distance(subarray_begin, subarray_end) + 1));
        }
      }
      return min_subarray_size;
    }

    template<typename Char>
    auto find_longest_distinct_substring_length(size_t max_distinct_chars,
    std::basic_string<Char> const& text) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<Char>::max() - numeric_limits<Char>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_substring_length = numeric_limits<size_t>::lowest();
      auto const text_begin = text.begin();
      auto const text_end = text.end();
      for (auto substring_begin = text_begin, substring_end = text_begin;
      substring_end != text_end; ++substring_end) {
        ++char_count[*substring_end];
        for (; size_t(count_if(begin(char_count), end(char_count), above_zero)) >
        max_distinct_chars; ++substring_begin) {
          --char_count[*substring_begin];
        }
        max_substring_length = max(max_substring_length,
          size_t(distance(substring_begin, substring_end) + 1));
      }
      return max_substring_length;
    }

    template<typename Item>
    size_t find_max_count_of_types_subarray_size(size_t types_count, std::vector<Item> array) {
      using namespace std;
      valarray<size_t> item_count(numeric_limits<Item>::max() - numeric_limits<Item>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_subarray_size = numeric_limits<size_t>::lowest();
      auto const array_begin = array.begin();
      auto const array_end = array.end();
      for (auto subarray_begin = array_begin, subarray_end = array_begin;
      subarray_end != array_end; ++subarray_end) {
        ++item_count[*subarray_end];
        for (; size_t(count_if(begin(item_count), end(item_count), above_zero)) > types_count;
        ++subarray_begin) {
          --item_count[*subarray_begin];
        }
        max_subarray_size = max(max_subarray_size,
          size_t(distance(subarray_begin, subarray_end) + 1));
      }
      return max_subarray_size;
    }
  }
}
