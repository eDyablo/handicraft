#include <cstddef>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace sprsmtrx {
    template<typename E>
    struct matrix2d_t {
      using element_t = E;
      using storage_t = std::unordered_map<size_t, element_t>;

      matrix2d_t(size_t rows, size_t columns):
       row_count(rows),
       column_count(columns) {
      }

      size_t size() const {
        return data.size();
      }

      void set(size_t row, size_t column, size_t value) {
        if (value) {
          data[get_key(row, column)] = value;
        }
      }

      element_t at(size_t row, size_t column) const {
        auto const entry_locator = data.find(get_key(row, column));
        return entry_locator != end(data) ? entry_locator->second : element_t();
      }

      auto operator*(std::vector<element_t> const& vector) const {
        std::vector<element_t> result(row_count, element_t());
        for (size_t row = 0; row < row_count; ++row) {
          for (size_t column = 0; column < column_count; ++column) {
            result[row] += at(row, column) * vector[column];
          }
        }
        return result;
      }

    private:
      constexpr size_t get_key(size_t row, size_t column) const {
        return column_count * row + column;
      }

      size_t row_count;
      size_t column_count;
      storage_t data;
    };
  }
}
