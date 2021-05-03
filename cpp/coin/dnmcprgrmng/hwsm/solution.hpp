#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<number_t>;

    namespace mztn {
      using how_sum_result_t = std::optional<number_set_t>;
      using how_sum_memo_t = std::unordered_map<number_t, how_sum_result_t>;

      /**
       * m = target sum
       * n = amount of numners
       *
       * Memoized solution:
       * time:  O(n * m^2)
       * space: O(m^2)
       **/
      how_sum_result_t how_sum(number_t target, number_set_t const& numbers,
                               how_sum_memo_t& memo) {
        using namespace std;
        if (memo.find(target) != memo.end()) return memo[target];
        if (target == 0) return number_set_t{};
        if (target < 0) return std::nullopt;
        how_sum_result_t combination;
        for (auto number : numbers) {
          auto const remainder = target - number;
          combination = how_sum(remainder, numbers, memo);
          if (combination.has_value()) {
            combination.value().push_back(number);
            memo[target] = combination;
            return combination;
          }
        }
        memo[target] = combination;
        return combination;
      }

      number_set_t how_sum(number_t target, number_set_t const& numbers) {
        how_sum_memo_t memo;
        return how_sum(target, numbers, memo).value_or(number_set_t{});
      }
    }  // namespace mztn

    namespace tbltn {
      using how_sum_record_t = std::optional<number_set_t>;
      using how_sum_table_t = std::vector<how_sum_record_t>;

      /**
       * m = target sum
       * n = amount of numners
       *
       * Tabulazed solution:
       * time:  O(n * m^2)
       * space: O(m^2)
       **/
      number_set_t how_sum(number_t target, number_set_t const& numbers) {
        how_sum_table_t table(target + 1);
        table[0] = number_set_t{};
        for (number_t sub_target = 0; sub_target <= target; ++sub_target) {
          if (table[sub_target].has_value()) {
            for (auto const number : numbers) {
              auto const sum = sub_target + number;
              if (sum <= target) {
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
