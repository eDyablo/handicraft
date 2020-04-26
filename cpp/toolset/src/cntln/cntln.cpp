#include "txtln.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

int main() {
  using namespace std;
  cout << accumulate(istream_iterator<line_t>(cin), istream_iterator<line_t>(),
    0, bind(plus<size_t>(), placeholders::_1, 1)) << endl;
  return 0;
}
