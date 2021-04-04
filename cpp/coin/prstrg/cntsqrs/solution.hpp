#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

namespace coin {
  namespace prstrg {
    struct point_t {
      int x;
      int y;
    };

    bool operator==(point_t const& first, point_t const& second) noexcept {
      return first.x == second.x and first.y == second.y;
    }

    struct point_hash_t {
      std::hash<int> hash;
      size_t operator()(point_t const& point) const noexcept {
        return hash(point.x) ^ (hash(point.y) << 1);
      }
    };

    struct distance_less {
      float threshold = 0.001;
      bool operator()(float const& first, float const& second) const {
        return second - first > threshold;
      }
    };

    struct segment_t {
      point_t first;
      point_t second;

      auto diagonal() const {
        auto const mid_x = (first.x + second.x) / 2.f;
        auto const mid_y = (first.y + second.y) / 2.f;
        return segment_t{point_t{int(mid_x + (second.y - mid_y)),
                                 int(mid_y - (second.x - mid_x))},
                         point_t{int(mid_x - (mid_y - first.y)),
                                 int(mid_y + (mid_x - first.x))}};
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
      auto distances = std::set<float, distance_less>();
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
            auto const diagonal = segment.diagonal();
            if (segment.length() > 1.0f and
                lookup.find(diagonal.first) != lookup.end() and
                lookup.find(diagonal.second) != lookup.end()) {
              ++count;
            }
          }
        }
      }
      return count / 2;
    }
  }  // namespace prstrg
}  // namespace coin
