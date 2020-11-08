#include <iostream>
#include <numeric>
#include <vector>

namespace coin {
  struct interval_t {
    int begin;
    int end;

    bool operator==(interval_t const& other) const {
      return begin == other.begin and end == other.end;
    }

    interval_t merged(interval_t const& other) const {
      using namespace std;
      return interval_t{min(begin, other.begin), max(end, other.end)};
    }

    bool overlap(interval_t const& other) const {
      return starts_within(other) or ends_within(other);
    }

    bool within(interval_t const& other) const {
      return starts_within(other) or ends_within(other);
    }

    bool includes(interval_t const& other) const {
      return other.within(*this);
    }

    bool starts_within(interval_t const& other) const {
      return other.begin <= begin and begin << other.end;
    }

    bool ends_within(interval_t const& other) const {
      return other.begin <= end and end << other.end;
    }
  };

  std::ostream& operator<<(std::ostream& stream, interval_t const& interval) {
    stream << "[" << interval.begin << ", " << interval.end << "]";
    return stream;
  }

  using interval_vector_t = std::vector<interval_t>;

  bool starts_before(interval_t const& first, interval_t const& second) {
    return first.begin < second.begin;
  }

  interval_vector_t merge(interval_vector_t intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    sort(begin(intervals), end(intervals), starts_before);
    interval_vector_t result{intervals.front()};
    for (auto const& current: intervals) {
      auto& last = result.back();
      if (last.overlap(current)) {
        last = last.merged(current);
      } else {
        result.push_back(current);
      }
    }
    return result;
  }

  interval_vector_t merge2(interval_vector_t intervals) {
    using namespace std;

    // Find leftmost value in the intervals to support negative values
    int leftmost = numeric_limits<int>::max();
    for (auto const& interval: intervals) {
      if (interval.begin < leftmost) {
        leftmost = interval.begin;
      }
    }

    int const index_base = -leftmost;

    vector<int> points;
    for (auto const& interval: intervals) {
      // Allocate enough points to place the interval
      auto const required_size = index_base + interval.end + 1;
      if (size(points) < required_size) {
        points.resize(required_size, 0);
      }
      // Mark points belong to the interval
      // A point belongs to an interval if sum of its value and
      // the previous point value greater than zero
      ++points[index_base + interval.begin]; // all points starting from the position have greater sum
      --points[index_base + interval.end]; // all points starting from the position will have less sum
    }

    // replace point markers with sums
    partial_sum(begin(points), end(points), begin(points));

    // construct disjoint intervals
    interval_vector_t result;
    auto const point_count = size(points);
    for (int point_index = 0; point_index < point_count;) {
      interval_t interval;
      while (points[point_index] == 0 and point_index < point_count) {
        ++point_index;
      }
      interval.begin = point_index - index_base;
      while (points[point_index] != 0 and point_index < point_count) {
        ++point_index;
      }
      interval.end = point_index - index_base;
      if (point_index < point_count) {
        result.push_back(interval);
      }
    }
    
    return result;
  }
}
