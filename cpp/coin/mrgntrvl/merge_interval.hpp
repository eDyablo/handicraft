#include <ostream>
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
}
