#pragma once

#include <limits>
#include <utility>
#include <valarray>

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
  }  // namespace two_pointers
}  // namespace coin
