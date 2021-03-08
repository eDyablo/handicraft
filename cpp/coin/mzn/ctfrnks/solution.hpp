#include <algorithm>
#include <functional>
#include <vector>

namespace coin {
  namespace mzn {
    auto rankup_count(size_t cutoff, std::vector<size_t> scores) {
      using namespace std;
      sort(begin(scores), end(scores), greater<size_t>());
      size_t rank = 1;
      for (size_t i = 1; i < size(scores); ++i) {
        if (scores[i] != scores[i - 1]) {
          rank = i + 1;
        }
        if (cutoff < rank) {
          return i;
        }
      }
      return size(scores);
    }
  }  // namespace mzn
}  // namespace coin
