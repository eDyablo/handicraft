#include <algorithm>
#include <iterator>
#include <vector>

namespace coin {
  namespace mcrsft {
    using block_vector_t = std::vector<size_t>;

    auto get_longest_distance(block_vector_t const& blocks) {
      using namespace std;
      auto length = size_t{0};
      auto left = begin(blocks), right = begin(blocks);
      for (; right != end(blocks); ++right) {
        if (*right < *(right - 1)) {
          length = max(length, size_t(distance(left, right)));
          while (left != right and (*left < *(left + 1))) {
            ++left;
          }
        }
      }
      return max(length, size_t(distance(left, right)));;
    }
  }  // namespace mcrsft
}  // namespace coin
