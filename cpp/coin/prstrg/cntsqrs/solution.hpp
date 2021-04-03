#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

namespace coin {
  namespace prstrg {
    struct point_t {
      int x;
      int y;
    };

    struct distance_less {
      float threshold = 0.001;
      bool operator()(float const& first, float const& second) const {
        return second - first > threshold;
      }
    };

    using point_vec_t = std::vector<point_t>;

    float distance(point_t const& first, point_t const& second) {
      auto const x_delta = first.x - second.x;
      auto const y_delta = first.y - second.y;
      return sqrt(x_delta * x_delta + y_delta * y_delta);
    }

    bool is_square(point_vec_t const& points) {
      auto distances = std::set<float, distance_less>();
      for (size_t i = 0; i < size(points); ++i) {
        for (size_t j = i + 1; j < size(points); ++j) {
          distances.insert(distance(points[i], points[j]));
        }
      }
      return size(distances) == 2;
    }
  }  // namespace prstrg
}  // namespace coin
