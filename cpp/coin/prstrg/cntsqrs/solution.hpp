#include <algorithm>
#include <cmath>
#include <unordered_set>

namespace coin {
  namespace prstrg {
    struct point_t {
      float x;
      float y;
    };

    bool operator==(point_t const& first, point_t const& second) noexcept {
      return first.x == second.x and first.y == second.y;
    }

    struct point_hash_t {
      std::hash<float> coord_hash;
      size_t operator()(point_t const& point) const noexcept {
        return coord_hash(point.x) ^ (coord_hash(point.y) << 1);
      }
    };

    struct segment_t {
      point_t first;
      point_t second;

      auto orthogonal() const {
        auto mid =
            point_t{(first.x + second.x) / 2.f, (first.y + second.y) / 2.f};
        auto delta = point_t{second.x - mid.x, second.y - mid.y};
        return segment_t{{(mid.x - delta.y), (mid.y + delta.x)},
                         {(mid.x + delta.y), (mid.y - delta.x)}};
      }

      float length() const {
        auto const x_delta = first.x - second.x;
        auto const y_delta = first.y - second.y;
        return sqrt(x_delta * x_delta + y_delta * y_delta);
      }
    };

    using point_vec_t = std::vector<point_t>;

    float distance(point_t const& first, point_t const& second) {
      auto const x_delta = first.x - second.x;
      auto const y_delta = first.y - second.y;
      return sqrt(x_delta * x_delta + y_delta * y_delta);
    }

    bool is_square(point_vec_t const& points) {
      auto distances = std::unordered_set<float>();
      for (size_t i = 0; i < size(points); ++i) {
        for (size_t j = i + 1; j < size(points); ++j) {
          distances.insert(distance(points[i], points[j]));
        }
      }
      return size(distances) == 2;
    }

    size_t count_squares(point_vec_t const& points) {
      using namespace std;
      auto lookup = unordered_set<point_t, point_hash_t>();
      for (auto& point : points) {
        lookup.insert(point);
      }
      size_t count = 0;
      for (size_t i = 0; i < size(points); ++i) {
        for (size_t j = i; j < size(points); ++j) {
          if (i != j) {
            auto const segment = segment_t{points[i], points[j]};
            auto const orthogonal = segment.orthogonal();
            if (lookup.find(orthogonal.first) != lookup.end() and
                lookup.find(orthogonal.second) != lookup.end()) {
              ++count;
            }
          }
        }
      }
      return count / 2;
    }
  }  // namespace prstrg
}  // namespace coin
