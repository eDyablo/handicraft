#include "cntrutl.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  using namespace std;
  transform(istream_iterator<string>(cin), istream_iterator<string>(),
    ostream_iterator<string>(cout, " "),
    bind(reversed<string>, placeholders::_1));
  cout << endl << flush;
  return 0;
}
