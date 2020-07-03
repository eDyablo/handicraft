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
  }  // namespace two_pointers
}  // namespace coin
