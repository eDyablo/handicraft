#pragma once

#include <limits>
#include <utility>
#include <valarray>
#include <vector>

namespace coin {
  namespace two_pointers {
    template <typename Item>
    auto find_target_sum_pair(Item target_sum,
                              std::valarray<Item> const& array) {
      using namespace std;
      auto const array_begin = begin(array);
      auto front_iterator = begin(array);
      auto back_iterator = end(array) - 1;
      while (front_iterator != back_iterator) {
        auto sum = *front_iterator + *back_iterator;
        if (sum > target_sum) {
          --back_iterator;
        } else if (sum < target_sum) {
          ++front_iterator;
        } else {
          return make_pair(size_t(distance(array_begin, front_iterator)),
                           size_t(distance(array_begin, back_iterator)));
        }
      }
      return make_pair(numeric_limits<size_t>::max(),
                       numeric_limits<size_t>::max());
    }

    template <typename Item>
    auto remove_duplicates(std::vector<Item>& array) {
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      auto subarray_end = array_begin + 1;
      for (auto iterator = array_begin; iterator != array_end; ++iterator) {
        if (*(subarray_end - 1) != *iterator) {
          *subarray_end = move(*iterator);
          ++subarray_end;
        }
      }
      return distance(array_begin, subarray_end);
    }

    template <typename Item>
    auto remove_all_inclusions(const Item& element, std::vector<Item>& array) {
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      auto subarray_end = array_begin;
      for (auto iterator = array_begin; iterator != array_end; ++iterator) {
        if (*iterator != element) {
          *subarray_end = move(*iterator);
          ++subarray_end;
        }
      }
      return distance(array_begin, subarray_end);
    }

    template <typename Item>
    auto make_squares(std::vector<int> const& array) {
      using namespace std;
      vector<Item> squares(size(array));
      auto left_iterator = begin(array);
      auto right_iterator = rbegin(array);
      for (auto squares_iterator = rbegin(squares);
           squares_iterator != squares.rend(); ++squares_iterator) {
        auto const left_square = (*left_iterator) * (*left_iterator);
        auto const right_square = (*right_iterator) * (*right_iterator);
        if (left_square > right_square) {
          *squares_iterator = left_square;
          ++left_iterator;
        } else {
          *squares_iterator = right_square;
          ++right_iterator;
        }
      }
      return squares;
    }
  }  // namespace two_pointers
}  // namespace coin
