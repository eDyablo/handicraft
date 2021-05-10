#pragma once

#include <unordered_map>
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

    namespace mztn {
      using count_sum_memo_t = std::unordered_map<size_t, size_t>;

      /**
       * m = targer sum
       * n = amount of numbers
       *
       * Memoized solution:
       * time:  O(?)
       * space: O(m*n)
       */
      size_t count_sum(number_t target, number_bank_t const& numbers,
                       size_t taken, count_sum_memo_t& memo) {
        auto const key = target * numbers.size() + taken;
        if (memo.find(key) != memo.end()) return memo[key];
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (taken >= numbers.size()) return 0;
        auto const sum =
            count_sum(target - numbers[taken], numbers, taken, memo) +
            count_sum(target, numbers, taken + 1, memo);
        memo[key] = sum;
        return sum;
      }

      size_t count_sum(number_t target, number_bank_t const& numbers) {
        count_sum_memo_t memo;
        return count_sum(target, numbers, 0, memo);
      }
    }  // namespace mztn

    namespace tbltn {
      using count_sum_table_t = std::vector<size_t>;

      size_t count_sum(number_t target, number_bank_t const& numbers) {
        count_sum_table_t table(target + 1, 0);
        table[0] = 1;
        for (number_t number : numbers) {
          for (number_t amount = 1; amount <= target; ++amount) {
            if (number <= amount) {
              table[amount] += table[amount - number];
            }
          }
        }
        return table[target];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
