#include <algorithm>
#include <string>
#include <vector>

namespace coin {
  namespace mzn {
    auto build_plan(std::string const& compartments) {
      using namespace std;
      auto plan = vector<int>(size(compartments), 0);
      auto left = distance(begin(compartments),
                           find(begin(compartments), end(compartments), '|'));
      for (auto right = 0; right < left; ++right) {
        plan[right] = -right;
      }
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

    auto partial_counts(std::string const& compartments) {
      using namespace std;
      auto counts = vector<size_t>(size(compartments), 0);
      for (size_t idx = 0, count = 0; idx < size(compartments); ++idx) {
        if (compartments[idx] == '*') {
          ++count;
        }
        counts[idx] = count;
      }
      return counts;
    }

    auto count_inventory(std::string const& compartments,
                         std::vector<size_t> const& starts,
                         std::vector<size_t> const& ends) {
      using namespace std;
      auto answer = vector<size_t>();
      if (not empty(compartments)) {
        auto const plan = build_plan(compartments);
        auto const counts = partial_counts(compartments);
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
          auto const sum = counts[end] - counts[start];
          if (start < end and sum > 0) {
            answer.push_back(sum);
          }
        }
      }
      return answer;
    }
  }  // namespace mzn
}  // namespace coin
