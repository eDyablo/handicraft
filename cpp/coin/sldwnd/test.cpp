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
  test(9u, find_max_sum_subarray<int>(3u, {2, 1, 5, 1, 3, 2}));
  test(7u, find_max_sum_subarray<int>(2u, {2, 3, 4, 1, 5}));
  test(2u, find_min_subarray<int>(7, {2, 1, 5, 2, 3, 2}));
  test(1u, find_min_subarray<int>(7, {2, 1, 5, 2, 8}));
  test(3u, find_min_subarray<int>(8, {3, 4, 1, 1, 6}));
  return 0;
}
