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
          auto const dist = distance(left, right);
          if (length < dist) {
            length = dist;
          }
          while (left != right and (*left < *(left + 1))) {
            ++left;
          }
        }
      }
      auto const dist = distance(left, right);
      if (length < dist) {
        length = dist;
      }
      return length;
    }
  }  // namespace mcrsft
}  // namespace coin
