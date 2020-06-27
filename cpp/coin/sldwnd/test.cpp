#include <iostream>

#include "sliding_window.hpp"

void test(size_t expected, size_t actual) {
  using namespace std;
  if (actual != expected) {
    cout << "expected: " << expected << endl
      << "actual: " << actual << endl << endl;
  }
}

int main() {
  using namespace std;
  using namespace coin::sliding_window;
  test(9, find_max_sum_subarray(3u, vector<int> {2, 1, 5, 1, 3, 2}));
  test(7, find_max_sum_subarray(2u, vector<int> {2, 3, 4, 1, 5}));
  return 0;
}
