#pragma once

#include <array>

namespace coin {
  using ostream = std::ofstream;

  template<size_t rows, size_t columns>
  ostream& operator<<(ostream& stream, int (&grid)[rows][columns]) {
    using namespace std;
    for (auto& row : grid) {
      copy(&row[0], &row[columns], ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    return stream;
  }

  template<size_t rows, size_t columns>
  size_t count_clusters(int (&grid)[rows][columns]) {
    size_t count = 0;
    return count;
  }
}
