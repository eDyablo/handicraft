#pragma once

#include "point.hpp"
#include "vector.hpp"

namespace gmtr {
  template<typename CoordT, size_t DimN>
  class basic_system_t {
  public:
    static size_t const dimention = DimN;
    typedef basic_system_t self_t;
    typedef CoordT coord_t;
    typedef basic_point_t<coord_t, dimention> point_t;
    typedef basic_vector_t<coord_t, dimention> vector_t;

  private:
    vector_t axes[dimention];

  public:
    static self_t world;
  };

  typedef basic_system_t<float, 2> system2_t;

  typedef basic_system_t<float, 3> system3_t;
}
