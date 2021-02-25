#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace coin {
  namespace microsoft {
    template <typename Number>
    Number sumup_digits(Number number) {
      auto sum = Number(0);
      for (; number; number /= 10) {
        sum += number % 10;
      }
      return sum;
    }

    template <typename Number>
    Number max_sum_of_equal_digits_sum_pair(
        std::vector<Number> const& numbers) {
      using namespace std;
      using pair_t = pair<Number, Number>;
      using pair_lookup_t = unordered_map<Number, pair_t>;
      pair_lookup_t pair_lookup;
      auto max_sum = Number(0);
      for (auto number : numbers) {
        auto digit_sum = sumup_digits(number);
        auto const location = pair_lookup.find(digit_sum);
        if (location == pair_lookup.end()) {
          pair_lookup.emplace(digit_sum, make_pair(Number(0), number));
        } else {
          auto& pair = location->second;
          if (pair.first < number) {
            pair.first = number;
          } else if (pair.second < number) {
            pair.second = number;
          }
          auto const sum = pair.first + pair.second;
          if (max_sum < sum) {
            max_sum = sum;
          }
        }
      }
      return max_sum != 0 ? max_sum : -1;
    }
  }  // namespace microsoft
}  // namespace coin
