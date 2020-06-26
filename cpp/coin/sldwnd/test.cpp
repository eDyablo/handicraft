#include <iostream>

#include "sliding_window.hpp"

int main() {
  using namespace std;
  using namespace coin::sliding_window;
  cout << find_max_sum_subarray(3u, vector<int> {2, 1, 5, 1, 3, 2}) << endl
    << find_max_sum_subarray(2u, vector<int> {2, 3, 4, 1, 5}) << endl;
  return 0;
}
