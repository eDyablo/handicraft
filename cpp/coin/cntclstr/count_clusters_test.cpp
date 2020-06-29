#include "count_clusters.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

template<size_t rows, size_t columns>
void test(int (&grid)[rows][columns], size_t expected_cluster_count) {
  using namespace coin;
  using namespace std;
  auto const cluster_count = count_clusters(grid);
  if (cluster_count != expected_cluster_count) {
    cout << grid
      << "expected " << expected_cluster_count << " custer(s)" << endl
      << "found " << cluster_count << " cluster(s)" << endl << endl;
  }
}

int main() {
  {
    int grid[][1] = {
      {0}
    };
    test(grid, 0);
  }
  {
    int grid[][1] = {
      {1}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {1, 0},
      {0, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 1},
      {0, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 0},
      {1, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 0},
      {0, 1}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {1, 1},
      {0, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 0},
      {1, 1}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {1, 0},
      {1, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 1},
      {0, 1}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {1, 1},
      {1, 0}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {1, 1},
      {0, 1}
    };
    test(grid, 1);
  }
  {
    int grid[][2] = {
      {0, 1},
      {1, 1}
    };
    test(grid, 1);
  }
  {
    int grid[][5] = {
      {1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1}
    };
    test(grid, 2);
  }
  {
    int grid[][7] = {
      {1, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 1},
    };
    test(grid, 7);
  }
  return 0;
}
