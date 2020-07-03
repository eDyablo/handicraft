#pragma once

#include <algorithm>
#include <limits>
#include <string>
#include <unordered_map>
#include <valarray>
#include <vector>

namespace coin {
  namespace sliding_window {
    template <typename Element>
    auto find_max_sum_subarray(size_t const subarray_size,
                               std::vector<Element> const& array) {
      size_t subarray_sum = 0;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      for (auto iter = array_begin; iter != array_begin + subarray_size;
           ++iter) {
        subarray_sum += *iter;
      }
      size_t max_sum = 0;
      for (auto subarray_begin = array_begin,
                subarray_end = array_begin + subarray_size;
           subarray_end != array_end; ++subarray_begin, ++subarray_end) {
        subarray_sum += *subarray_end - *subarray_begin;
        max_sum = std::max(max_sum, subarray_sum);
      }
      return max_sum;
    }

    template <typename Element>
    auto find_smallest_subarray_size(Element const sum,
                                     std::vector<Element> const& array) {
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
          min_subarray_size = min<size_t>(
              min_subarray_size, distance(subarray_begin, subarray_end + 1));
        }
      }
      return min_subarray_size;
    }

    template <typename Char>
    auto find_longest_distinct_substring_size(
        size_t const max_distinct_chars,
        std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<Char>::max() -
                                  numeric_limits<Char>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_substring_length = numeric_limits<size_t>::lowest();
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
           substring_end != string_end; ++substring_end) {
        ++char_count[*substring_end];
        for (; size_t(count_if(begin(char_count), end(char_count),
                               above_zero)) > max_distinct_chars;
             ++substring_begin) {
          --char_count[*substring_begin];
        }
        max_substring_length = max<size_t>(
            max_substring_length, distance(substring_begin, substring_end + 1));
      }
      return max_substring_length;
    }

    template <typename Item>
    auto find_max_count_of_types_subarray_size(size_t const types_count,
                                               std::vector<Item> array) {
      using namespace std;
      valarray<size_t> item_count(numeric_limits<Item>::max() -
                                  numeric_limits<Item>::min() + 1);
      auto const above_zero = [](size_t item) { return item > 0u; };
      auto max_subarray_size = numeric_limits<size_t>::lowest();
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      for (auto subarray_begin = array_begin, subarray_end = array_begin;
           subarray_end != array_end; ++subarray_end) {
        ++item_count[*subarray_end];
        for (; size_t(count_if(begin(item_count), end(item_count),
                               above_zero)) > types_count;
             ++subarray_begin) {
          --item_count[*subarray_begin];
        }
        max_subarray_size = max<size_t>(
            max_subarray_size, distance(subarray_begin, subarray_end + 1));
      }
      return max_subarray_size;
    }

    template <typename Char>
    auto find_longest_no_repeating_substring(
        std::basic_string<Char> const& string) {
      using namespace std;
      using iterator_t = basic_string<Char>::const_iterator;
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      valarray<iterator_t> char_position(
          string_end,
          numeric_limits<Char>::max() - numeric_limits<Char>::min() + 1);
      auto max_substring_size = numeric_limits<size_t>::lowest();
      for (auto substring_begin = string_begin, substring_end = string_begin;
           substring_end != string_end; ++substring_end) {
        if (char_position[*substring_end] != string_end) {
          substring_begin = char_position[*substring_end] + 1;
        }
        char_position[*substring_end] = substring_end;
        max_substring_size = max<size_t>(
            max_substring_size, distance(substring_begin, substring_end + 1));
      }
      return max_substring_size;
    }

    template <typename Char>
    auto find_longest_same_letter_substring_size(
        size_t const max_replacements, std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<Char>::max() -
                                  numeric_limits<Char>::min() + 1u);
      auto max_substring_size = numeric_limits<size_t>::min();
      auto max_repeated_count = numeric_limits<size_t>::min();
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
           substring_end != string_end; ++substring_end) {
        max_repeated_count =
            max(max_repeated_count, ++char_count[*substring_end]);
        auto const substring_size =
            size_t(distance(substring_begin, substring_end + 1));
        if (substring_size - max_repeated_count > max_replacements) {
          --char_count[*(substring_begin++)];
        }
        max_substring_size = max<size_t>(
            max_substring_size, distance(substring_begin, substring_end + 1));
      }
      return max_substring_size;
    }

    template <typename Item>
    auto find_longest_same_item_subarray_size(Item const item,
                                              size_t max_replacements,
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
        max_subarray_size = max<size_t>(
            max_subarray_size, distance(subarray_begin, subarray_end + 1));
      }
      return max_subarray_size;
    }

    template <typename Char>
    auto contains_permutation(std::basic_string<Char> const& pattern,
                              std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<char>::max() -
                                  numeric_limits<char>::min() + 1);
      for (auto item : pattern) {
        ++char_count[item];
      }
      size_t expected_matched_char_count = count_if(
          begin(char_count), end(char_count), [](size_t it) { return it > 0; });
      size_t matched_char_count = 0;
      auto const pattern_size = size(pattern);
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
        if (substring_end >= string_begin + pattern_size - 1) {
          if (char_count[*substring_begin] == 0) {
            --matched_char_count;
          }
          ++char_count[*substring_begin];
          ++substring_begin;
        }
      }
      return false;
    }

    template <typename Char>
    auto find_anagrams(std::basic_string<Char> const& pattern,
                       std::basic_string<Char> const& string) {
      using namespace std;
      valarray<size_t> char_count(numeric_limits<char>::max() -
                                  numeric_limits<char>::min() + 1);
      for (auto item : pattern) {
        ++char_count[item];
      }
      size_t expected_matched_char_count =
          count_if(begin(char_count), end(char_count),
                   [](size_t item) { return item > 0; });
      size_t matched_char_count = 0;
      vector<size_t> indices;
      auto const pattern_size = size(pattern);
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto substring_begin = string_begin, substring_end = string_begin;
           substring_end != string_end; ++substring_end) {
        --char_count[*substring_end];
        if (char_count[*substring_end] == 0) {
          ++matched_char_count;
        }
        if (matched_char_count == expected_matched_char_count) {
          indices.push_back(distance(string_begin, substring_begin));
        }
        if (substring_end >= string_begin + pattern_size - 1) {
          if (char_count[*substring_begin] == 0) {
            --matched_char_count;
          }
          ++char_count[*substring_begin];
          ++substring_begin;
        }
      }
      return indices;
    }

    template <typename Letter>
    auto find_smallest_all_letters_substring(
        std::basic_string<Letter> const& pattern,
        std::basic_string<Letter> const& string) {
      using letter_t = Letter;
      using string_t = std::basic_string<letter_t>;
      using namespace std;
      valarray<size_t> letter_count(numeric_limits<letter_t>::max() -
                                    numeric_limits<letter_t>::min() + 1);
      for (auto letter : pattern) {
        ++letter_count[letter];
      }
      auto expected_matched_letter_count =
          count_if(begin(letter_count), end(letter_count),
                   [](size_t item) { return item > 0; });
      auto matched_letter_count = numeric_limits<size_t>::min();
      auto const pattern_size = size(pattern);
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      auto smallest_substring_begin = string_begin;
      auto smallest_substring_end = string_end;
      auto smallest_substring_size = numeric_limits<size_t>::max();
      for (auto substring_begin = string_begin, substring_end = string_begin;
           substring_end != string_end; ++substring_end) {
        --letter_count[*substring_end];
        if (letter_count[*substring_end] == 0) {
          ++matched_letter_count;
        }
        while (matched_letter_count == expected_matched_letter_count) {
          auto const substring_size =
              size_t(distance(substring_begin, substring_end + 1));
          smallest_substring_size =
              distance(smallest_substring_begin, smallest_substring_end);
          if (substring_size < smallest_substring_size) {
            smallest_substring_begin = substring_begin;
            smallest_substring_end = substring_end + 1;
          }
          if (letter_count[*substring_begin] == 0) {
            --matched_letter_count;
          }
          ++letter_count[*substring_begin];
          ++substring_begin;
        }
      }
      if (smallest_substring_size < numeric_limits<size_t>::max()) {
        return string_t(smallest_substring_begin, smallest_substring_end);
      } else {
        return string_t();
      }
    }

    template <typename Char>
    auto find_word_concatenation(
        std::vector<std::basic_string<Char>> const& words,
        std::basic_string<Char> const& string) {
      using char_t = Char;
      using string_t = std::basic_string<char_t>;
      using word_map_t = std::unordered_map<string_t, size_t>;
      using namespace std;
      word_map_t expected_words;
      for (auto const& word : words) {
        ++expected_words[word];
      }
      vector<size_t> indices;
      auto const word_count = size(words);
      auto const word_size = word_count > 0 ? size(words.front()) : size_t(0);
      auto const string_begin = begin(string);
      auto const string_end = end(string);
      for (auto string_iter = string_begin; string_iter != string_end;
           ++string_iter) {
        word_map_t seen_words;
        for (auto lookup_iter = string_iter;
             size_t(distance(lookup_iter, string_end)) >= word_size;
             lookup_iter += word_size) {
          string_t const lookup_word(lookup_iter, lookup_iter + word_size);
          auto expected_word_record = expected_words.find(lookup_word);
          if (expected_word_record != end(expected_words)) {
            auto seen_word_record =
                seen_words.try_emplace(begin(seen_words), lookup_word);
            ++(seen_word_record->second);
            if (seen_word_record->second > expected_word_record->second) {
              break;
            }
          }
        }
        if (size(seen_words) == size(expected_words)) {
          indices.push_back(distance(string_begin, string_iter));
        }
      }
      return indices;
    }
  }  // namespace sliding_window
}  // namespace coin
