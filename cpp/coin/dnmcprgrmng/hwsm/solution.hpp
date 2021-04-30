#include <algorithm>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using number_t = int;
    using number_set_t = std::vector<number_t>;
    using memo_record_t = std::pair<bool, number_set_t>;
    using how_sum_memo_t = std::unordered_map<number_t, memo_record_t>;

    bool how_sum(number_t target, number_set_t const& numbers,
                 number_set_t& set, how_sum_memo_t& memo) {
      using namespace std;
      if (memo.find(target) != memo.end()) {
        set = memo[target].second;
        return memo[target].first;
      }
      set = number_set_t{};
      if (target == 0) {
        return true;
      }
      if (target < 0) {
        return false;
      }
      for (auto number : numbers) {
        auto const remainder = target - number;
        if (how_sum(remainder, numbers, set, memo)) {
          set.push_back(number);
          memo[target] = make_pair(true, set);
          return true;
        }
      }
      memo[target] = make_pair(false, set);
      return false;
    }

    number_set_t how_sum(number_t target, number_set_t const& numbers) {
      number_set_t set;
      how_sum_memo_t memo;
      how_sum(target, numbers, set, memo);
      return set;
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
