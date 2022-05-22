#include <vector>

namespace coin {
  namespace mzn {
    auto count_decreasing_ratings(std::vector<int> const& ratings) {
      auto const ratings_size = size(ratings);
      size_t count = 0;
      for (size_t left = 0, right = 1; left < ratings_size; left = right++) {
        while (right < ratings_size &&
               ratings[left] - ratings[right] == right - left) {
          ++right;
        }
        auto const group_size = right - left;
        count += group_size * (group_size + 1) / 2;
      }
      return count;
    }
  }  // namespace mzn
}  // namespace coin
