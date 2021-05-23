#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

namespace coin {
  template<size_t rows, size_t columns>
  std::ostream& operator<<(std::ostream& stream, int (&grid)[rows][columns]) {
    using namespace std;
    for (auto& row : grid) {
      copy(&row[0], &row[columns], ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    return stream;
  }

  template<size_t rows, size_t columns>
  size_t count_clusters(int (&grid)[rows][columns]) {
    for (size_t row = 0; row < rows; ++row) {
      for (size_t col = 0; col < columns; ++col) {
        auto& cell_value = grid[row][col];
        if (cell_value > 0 && cell_value < 3) {
          cell_value = 2;
          if (col > 0) {
            auto& left_cell = grid[row][col - 1];
            if (left_cell == 1) left_cell = 3;
          }
          if (row > 0) {
            auto& above_cell = grid[row - 1][col];
            if (above_cell == 1) above_cell = 3;
          }
          if (col < columns - 1) {
            auto& right_cell = grid[row][col + 1];
            if (right_cell == 1) right_cell = 3;
          }
          if (row < row - 1) {
            auto& below_cell = grid[row + 1][col];
            if (below_cell == 1) below_cell = 3;
          }
        }
      }
    }
    using namespace std;
    return count_if(&grid[0][0], &grid[rows][columns], [](int value) { return value == 2; });
  }
}
