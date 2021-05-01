#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<int>;
    using can_sum_memo = std::unordered_map<int, bool>;

    bool can_sum(int target, number_set_t const& numbers, can_sum_memo& memo) {
      if (memo.find(target) != memo.end()) return memo[target];
      if (target == 0) return true;
      if (target < 0) return false;
      for (auto number : numbers) {
        if (can_sum(target - number, numbers, memo)) {
          memo[target] = true;
          return true;
        }
      }
      memo[target] = false;
      return false;
    }

    bool can_sum(int target, number_set_t const& numbers) {
      can_sum_memo memo;
      return can_sum(target, numbers, memo);
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
