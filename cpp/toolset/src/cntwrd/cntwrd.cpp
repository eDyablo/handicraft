#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

int main() {
  using namespace std;
  cout << accumulate(istream_iterator<string>(cin), istream_iterator<string>(),
    0, bind(plus<size_t>(), placeholders::_1, 1)) << endl;
  return 0;
}
