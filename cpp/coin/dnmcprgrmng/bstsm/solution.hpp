#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<number_t>;
    namespace mztn {
      using best_sum_result_t = std::optional<number_set_t>;
      using best_sum_memo_t = std::unordered_map<number_t, best_sum_result_t>;

      /**
       * m = target sum
       * n = amount of numners
       *
       * Memoized solution:
       * time:  O(n * m^2)
       * space: O(m^2)
       **/
      best_sum_result_t best_sum(number_t target, number_set_t const& numbers,
                                 best_sum_memo_t& memo) {
        if (memo.find(target) != memo.end()) return memo[target];
        if (target == 0) return number_set_t{};
        if (target < 0) return std::nullopt;
        best_sum_result_t shortest_combination;
        for (auto number : numbers) {
          auto const reminder = target - number;
          auto combination = best_sum(reminder, numbers, memo);
          if (combination.has_value()) {
            combination.value().push_back(number);
            if (not shortest_combination.has_value() or
                size(combination.value()) <
                    size(shortest_combination.value())) {
              shortest_combination = combination;
            }
          }
        }
        memo[target] = shortest_combination;
        return shortest_combination;
      }

      number_set_t best_sum(number_t target, number_set_t const& numbers) {
        best_sum_memo_t memo;
        return best_sum(target, numbers, memo).value_or(number_set_t{});
      }
    }  // namespace mztn

    namespace tbltn {
      using best_sum_record_t = std::optional<number_set_t>;
      using best_sum_table_t = std::vector<best_sum_record_t>;

      /**
       * m = target sum
       * n = amount of numners
       *
       * Tabulated solution:
       * time:  O(n * m^2)
       * space: O(m^2)
       **/
      number_set_t best_sum(number_t target, number_set_t const& numbers) {
        best_sum_table_t table(target + 1);
        table[0] = number_set_t{};
        for (number_t sub_target = 0; sub_target <= target; ++sub_target) {
          if (table[sub_target].has_value()) {
            for (auto const number : numbers) {
              auto const sum = sub_target + number;
              if (sum <= target) {
                if (table[sum].has_value() and
                    size(table[sum].value()) <= size(table[sub_target].value()))
                  continue;
                table[sum] = table[sub_target];
                table[sum].value().push_back(number);
              }
            }
          }
        }
        return table[target].value_or(number_set_t{});
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
