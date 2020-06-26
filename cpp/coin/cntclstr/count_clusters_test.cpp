#include "count_clusters.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>



int main() {
  using namespace std;
  using namespace coin;
  int grid[][5] = {
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1}
  };
  cout << count_clusters(grid) << endl << grid << endl;
  return 0;
}
