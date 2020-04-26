#include "txtln.hpp"
#include "cntrutl.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  using namespace std;
  transform(istream_iterator<line_t>(cin), istream_iterator<line_t>(),
    ostream_iterator<string>(cout, "\n"),
    bind(reversed<string>, bind(&line_t::str, placeholders::_1)));
  return 0;
}
