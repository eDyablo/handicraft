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
      auto answer = vector<size_t>();
      if (not empty(compartments)) {
        auto const plan = build_plan(compartments);
        auto const interval_count = min(size(starts), size(ends));
        for (auto i = 0; i < interval_count; ++i) {
          auto start = starts[i] - 1;
          auto end = min(size(plan), ends[i]) - 1;
          if (plan[start] < 0) {
            start += plan[start];
          }
          if (plan[end] < 0) {
            end += plan[end];
          }
          size_t sum = 0;
          for (; start < end;) {
            auto const count = plan[start];
            sum += count;
            start += count + 1;
          }
          if (sum > 0) {
            answer.push_back(sum);
          }
        }
      }
      return answer;
    }
  }  // namespace mzn
}  // namespace coin