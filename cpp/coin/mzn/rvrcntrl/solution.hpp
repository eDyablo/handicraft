#include <string>
#include <vector>

namespace coin {
  namespace mzn {
    using command_t = std::string;
    using programm_t = std::vector<command_t>;

    struct location_t {
      size_t row;
      size_t column;
    };

    struct plan_t {
      size_t size;

      location_t up(location_t const& origin) const {
        return origin.row > 0 ? location_t{origin.row - 1, origin.column}
                              : origin;
      }

      location_t down(location_t const& origin) const {
        return origin.row < size ? location_t{origin.row + 1, origin.column}
                                 : origin;
      }

      location_t left(location_t const& origin) const {
        return origin.column > 0 ? location_t{origin.row, origin.column - 1}
                                 : origin;
      }

      location_t right(location_t const& origin) const {
        return origin.column < size ? location_t{origin.row, origin.column + 1}
                                    : origin;
      }

      size_t position(location_t const& location) const {
        return location.row * size + location.column;
      }
    };

    auto move_rover(size_t size, programm_t const& programm) {
      plan_t plan{size};
      location_t location{0, 0};
      for (auto command : programm) {
        if (command == "UP") {
          location = plan.up(location);
        } else if (command == "DOWN") {
          location = plan.down(location);
        } else if (command == "LEFT") {
          location = plan.left(location);
        } else if (command == "RIGHT") {
          location = plan.right(location);
        }
      }
      return plan.position(location);
    }
  }  // namespace mzn
}  // namespace coin
