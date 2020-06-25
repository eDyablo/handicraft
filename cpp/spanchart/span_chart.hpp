#include <algorithm>
#include <limits>
#include <map>

template<class Point, class Value>
class span_chart_t {
  using point_t = Point;
  using value_t = Value;
  using map_t = std::map<point_t, value_t>;

  map_t chart;

public:
  point_t const lowest_point = std::numeric_limits<point_t>::lowest();
  point_t const  highest_point = std::numeric_limits<point_t>::max();

public:
  span_chart_t(Value const& value) {
    chart.emplace_hint(chart.begin(), lowest_point, value);
  }

  void enroll(point_t const& from, point_t const& to, value_t const& value) {
    if (!(from < to))
      return;

    auto begin = chart.lower_bound(from);
    auto end = chart.upper_bound(to);

    if (begin != chart.begin()) {
      --begin;
      if (!(begin->second == value))
        ++begin;
    }

    auto const end_value = (--end)->second;

    auto const erased = chart.erase(begin, ++end);

    if (!(end_value == value)) {
      auto inserted = chart.emplace_hint(erased, from, value);
      chart.emplace_hint(++inserted, to, end_value);
    }
    
    if (chart.size() == 0) {
      chart.emplace_hint(chart.end(), lowest_point, value);
    } else {
      chart.emplace_hint(chart.end(), to, end_value);
    }
  }


  value_t const& operator[](point_t const& point) const {
    auto const& [location, value] = *(--chart.upper_bound(point));
    return value;
  }

  size_t entries_count() const { return chart.size(); }

  bool is_dense() const {
    using namespace std;
    using pair_t = decltype(chart)::value_type;
    return adjacent_find(chart.cbegin(), chart.cend(),
      [](pair_t const& f, pair_t const& s) { return f.second == s.second; }) == chart.end();
  }
};
