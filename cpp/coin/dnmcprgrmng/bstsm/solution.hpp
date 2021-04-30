#pragma once

#include <algorithm>
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
      if (memo.find(target) != end(memo)) return memo[target];
      if (target == 0) return number_set_t{};
      if (target < 0) return std::nullopt;
      number_set_t set;
      for (auto number : numbers) {
        auto const reminder = target - number;
        auto sub_result = best_sum(reminder, numbers, memo);
        if (sub_result.has_value()) {
          auto sub_set = sub_result.value();
          sub_set.push_back(number);
          if (empty(set) or size(sub_set) < size(set)) {
            set = sub_set;
          }
        }
      }
      if (empty(set)) {
        memo[target] = std::nullopt;
      } else {
        memo[target] = set;
      }
      return memo[target];
    }

    number_set_t best_sum(number_t target, number_set_t const& numbers) {
      best_sum_memo_t memo;
      return best_sum(target, numbers, memo).value_or(number_set_t{});
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
