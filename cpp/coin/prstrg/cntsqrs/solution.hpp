#include <cmath>

namespace coin {
  namespace prstrg {
    struct point_t {
      int x;
      int y;
    };

    float distance(point_t const& first, point_t const& second) {
      auto const x_delta = first.x - second.x;
      auto const y_delta = first.y - second.y;
      return sqrt(x_delta * x_delta + y_delta * y_delta);
    }
  }  // namespace prstrg
}  // namespace coin
