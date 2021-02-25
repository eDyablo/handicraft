#include <algorithm>
#include <vector>

namespace coin {
  namespace prfxtbl {
    template< typename I>
    auto make_table(I begin, I end) {
      using namespace std;
      auto const size = std::distance(begin, end) - 1;
      auto table = std::vector<size_t>(size);
      auto prefix_right = begin;
      auto suffix_left = begin; ++suffix_left;
      auto table_iter = table.begin();
      for (; suffix_left != end; ++suffix_left, ++table_iter) {
        while (prefix_right != begin and *prefix_right != *suffix_left) {
          prefix_right = begin + 
        }
        if (*prefix_right == *suffix_left) {
          ++prefix_right;
        }
        *table_iter = distance(begin, prefix_right);
      }
      return table;
    }

    template<typename E>
    auto make(E const* begin, E const* end) {
      return make_table<E const*>(begin, end);
    }

    template<typename E, size_t N>
    auto make(const E (&array)[N]) {
      return make(&array[0], &array[N]);
    }
  }
}
