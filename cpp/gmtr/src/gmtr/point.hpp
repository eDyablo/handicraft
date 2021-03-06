#pragma once

#include <cstddef>
#include <ostream>
#include <iterator>
#include <algorithm>

namespace gmtr {
  template<typename CoordT, size_t DimN>
  class basic_point_t {
  public:
    static size_t const dimention = DimN;
    typedef basic_point_t self_t;
    typedef CoordT coord_t;

  private:
    coord_t coords[DimN] = {0};

  public:
    static self_t const origin;

    auto const& get_coords() const {
      return coords;
    }

    friend std::ostream& operator<<(std::ostream& stream, self_t const& point) {
      using namespace std;
      auto const& coords = point.coords;
      stream << "p(";
      copy(&coords[0], &coords[dimention-1], ostream_iterator<coord_t>(stream, ","));
      stream << coords[dimention-1] << ')';
      return stream;
    }
  };

  typedef basic_point_t<float, 2> point2_t;

  typedef basic_point_t<float, 3> point3_t;
}
