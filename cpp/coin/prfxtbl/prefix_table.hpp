#include <algorithm>
#include <vector>

namespace coin {
  namespace prfxtbl {
    template< typename I>
    auto make_table(I begin, I end) {
      auto const size = std::distance(begin, end) - 1;
      return std::vector<size_t>(size);
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
