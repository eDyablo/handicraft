#include <algorithm>
#include <string>
#include <vector>

namespace coin {
  namespace mzn {
    auto build_plan(std::string const& compartments) {
      using namespace std;
      auto plan = vector<int>(size(compartments), 0);
      auto left = distance(find(begin(compartments), end(compartments), '|'),
                           begin(compartments));
      for (auto right = left + 1; right < size(compartments); ++right) {
        if (compartments[right] == '*') {
          plan[right] = left - right;
        } else if (compartments[right] == '|') {
          plan[left] = right - left - 1;
          left = right;
        }
      }
      return plan;
    }

    auto count_inventory(std::string const& compartments,
                         std::vector<size_t> const& starts,
                         std::vector<size_t> const& ends) {
      using namespace std;
      auto const plan = build_plan(compartments);
      auto answer = vector<size_t>();
      for (auto i = 0; i < size(starts); ++i) {
        auto const start = starts[i] - 1;
        auto const end = ends[i] - 1;
        auto left = start;
        if (plan[left] < 0) {
          left += plan[left];
        }
        size_t sum = 0;
        do {
          auto const count = plan[left];
          sum += count;
          left += count + 1;
        } while (left < end - 1);
        answer.push_back(sum);
      }
      return answer;
    }
  }  // namespace mzn
}  // namespace coin