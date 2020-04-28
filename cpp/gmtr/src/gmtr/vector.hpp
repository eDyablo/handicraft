#pragma once

#include "point.hpp"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <ostream>

namespace gmtr {
  template<typename CoordT, size_t DimN>
  class basic_vector_t {
  public:
    static size_t const dimention = DimN;
    typedef basic_vector_t self_t;
    typedef CoordT coord_t;
    typedef basic_point_t<coord_t, dimention> point_t;

  private:
    point3_t terminal;

  public:
    auto dot_product(self_t const& another) {
      using namespace std;
      auto const& self_coords = terminal.get_coords();
      auto const& another_coords = another.terminal.get_coords();
      return inner_product(&self_coords[0], &self_coords[dimention],
        &another_coords[0], coord_t());
    }

    auto scalar_product(self_t const& another) {
      return dot_product(another);
    }

    friend std::ostream& operator<<(std::ostream& stream, self_t const& vector) {
      using namespace std;
      auto const& coords = vector.terminal.get_coords();
      stream << "v(";
      copy(&coords[0], &coords[dimention-1], ostream_iterator<coord_t>(stream, ","));
      stream << coords[dimention-1] << ')';
      return stream;
    }
  };

  typedef basic_vector_t<float, 2> vector2_t;

  typedef basic_vector_t<float, 3> vector3_t;
}
