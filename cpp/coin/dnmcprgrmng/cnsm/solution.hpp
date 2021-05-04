#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<int>;

    namespace brtfrc {
      /**
       * m = target sum
       * n = amount of numbers
       *
       * Brute force solution:
       * time:  O(n^m)
       * space: O(m)
       */
      bool can_sum(int target, number_set_t const& numbers) {
        if (target == 0) return true;
        if (target < 0) return false;
        for (auto number : numbers) {
          if (can_sum(target - number, numbers)) {
            return true;
          }
        }
        return false;
      }
    }  // namespace brtfrc

    namespace mztn {
      using can_sum_memo = std::unordered_map<int, bool>;

      bool can_sum(int target, number_set_t const& numbers,
                   can_sum_memo& memo) {
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
    }  // namespace mztn

    namespace tbltn {
      using can_sum_table = std::vector<bool>;

      /**
       * m = target sum
       * n = numbers count
       *
       * Tabulated solution:
       * time:  O(m * n)
       * space: O(m)
       */
      bool can_sum(number_t target, number_set_t const& numbers) {
        can_sum_table table(target + 1, 0);
        table[0] = true;
        for (number_t sub_target = 0; sub_target <= target; ++sub_target) {
          if (table[sub_target]) {
            for (auto number : numbers) {
              auto const sum = sub_target + number;
              if (sum <= target) table[sum] = true;
            }
          }
        }
        return table[target];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
