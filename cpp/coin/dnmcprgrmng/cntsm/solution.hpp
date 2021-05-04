#pragma once

#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = long;
    using number_bank_t = std::vector<number_t>;

    namespace brtfrc {
      /**
       * m = targer sum
       * n = amount of numbers
       * 
       * Brute force solution:
       * time:  O(2^?)
       * space: O(?)
       */ 
      size_t count_sum(number_t target, number_bank_t const& numbers,
                       size_t taken = 0) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (taken >= numbers.size()) return 0;
        return count_sum(target - numbers[taken], numbers, taken) +
               count_sum(target, numbers, taken + 1);
      }
    }  // namespace brtfrc
  }    // namespace dnmcprgrmng
}  // namespace coin
