#pragma once

#include "system.hpp"
#include <cstddef>

namespace gmtr {
  template<typename CoordT, size_t DimN>
  class basic_space_t {
  public:
    static const size_t dimention = DimN;
    typedef basic_space_t self_t;
    typedef CoordT coord_t;
    typedef basic_system_t<coord_t, dimention> system_t;

  private:
    system_t system;
  };

  typedef basic_space_t<float, 2> space2_t;

  typedef basic_space_t<float, 3> space3_t;
}
