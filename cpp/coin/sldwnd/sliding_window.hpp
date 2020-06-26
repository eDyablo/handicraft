#pragma once

#include <algorithm>
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
      size_t sum = 0;
      for (auto subarray_begin = begin, subarray_end = begin + subarray_size; subarray_end != end;
        ++subarray_begin, ++subarray_end) {
        subarray_sum += *subarray_end - *subarray_begin;
        sum = std::max(sum, subarray_sum);
      }
      return sum;
    }
  }
}
