#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<number_t>;
    using how_sum_result_t = std::optional<number_set_t>;
    using how_sum_memo_t = std::unordered_map<number_t, how_sum_result_t>;

    /**
     * m = target
     * n = length of numbers array
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
  }  // namespace dnmcprgrmng
}  // namespace coin
