#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace coin {
  namespace microsoft {
    template <typename Number>
    std::string number_to_string(Number number) {
      std::stringstream stream;
      stream << number;
      return stream.str();
    }

    template <typename Number>
    Number symbol_to_number(char symbol) {
      return Number(symbol - '0');
    }

    template <typename Number>
    Number sumup_digits(Number number) {
      auto sum = Number(0);
      for (auto symbol : number_to_string(number)) {
        sum += symbol_to_number<Number>(symbol);
      }
      return sum;
    }

    template <typename Number>
    Number max_sum_of_equal_digits_sum_pair(
        std::vector<Number> const& numbers) {
      using namespace std;
      using pair_t = pair<Number, Number>;
      using lookup_t = unordered_map<Number, pair_t>;
      lookup_t lookup;
      for (auto number : numbers) {
        auto digit_sum = sumup_digits(number);
        auto location = lookup.find(digit_sum);
        if (location == lookup.end()) {
          lookup.emplace(digit_sum, make_pair(Number(0), number));
        } else {
          auto& pair = location->second;
          if (pair.first < number) {
            pair.first = number;
          } else if (pair.second < number) {
            pair.second = number;
          }
        }
      }
      auto max_sum = Number(0);
      for (auto record : lookup) {
        auto const& pair = record.second;
        if (pair.first != 0) {
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
