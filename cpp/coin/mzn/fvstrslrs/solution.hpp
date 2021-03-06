#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

namespace coin {
  namespace mzn {
    struct review_t {
      review_t(size_t high, size_t all) : high(high), all(all) {
        ratio = float(high) / all;
        delta = (float(high + 1) / (all + 1)) - ratio;
      }

      auto get_ratio() const { return ratio; }

      auto get_delta() const { return delta; }

      review_t raised() const { return review_t(high + 1, all + 1); }

     private:
      size_t high;
      size_t all;
      float ratio;
      float delta;
    };

    auto sumup_ratio(std::vector<review_t> const& reviews) {
      float sum = 0.0;
      for (auto review : reviews) {
        sum += review.get_ratio();
      }
      return sum;
    }

    auto reviews_needed(std::vector<review_t> reviews, int threshold) {
      using namespace ::std;

      float threshold_sum = threshold * size(reviews) / 100.0;

      auto compare_delta = [](review_t first, review_t second) {
        return first.get_delta() < second.get_delta();
      };

      auto compare = compare_delta;
      make_heap(begin(reviews), end(reviews), compare);

      float sum = sumup_ratio(reviews);
      size_t count = 0;
      for (; sum < threshold_sum; ++count) {
        pop_heap(begin(reviews), end(reviews), compare);
        sum -= reviews.back().get_ratio();
        reviews.back() = reviews.back().raised();
        sum += reviews.back().get_ratio();
        push_heap(begin(reviews), end(reviews), compare);
      }

      return count;
    }
  }  // namespace mzn
}  // namespace coin
