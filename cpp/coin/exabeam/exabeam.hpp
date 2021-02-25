#include <unordered_map>
#include <vector>

namespace coin {
  namespace exabeam {
    template <typename Number>
    Number sumup_non_unique(std::vector<Number> const& numbers) {
      std::unordered_map<Number, size_t> lookup;
      for (auto n : numbers) {
        ++lookup[n];
      }
      auto sum = Number(0);
      for (auto pair : lookup) {
        if (pair.second > 1) {
          sum += pair.first * pair.second;
        }
      }
      return sum;
    }
  }  // namespace exabeam
}  // namespace coin
