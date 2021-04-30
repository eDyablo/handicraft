#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<number_t>;
    using best_sum_result_t = std::optional<number_set_t>;
    using best_sum_memo_t = std::unordered_map<number_t, best_sum_result_t>;

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
              size(combination.value()) < size(shortest_combination.value())) {
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
  }  // namespace dnmcprgrmng
}  // namespace coin
