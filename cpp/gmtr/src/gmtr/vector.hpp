#pragma once

#include "point.hpp"

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
  };

  typedef basic_vector_t<float, 2> vector2_t;

  typedef basic_vector_t<float, 3> vector3_t;
}
