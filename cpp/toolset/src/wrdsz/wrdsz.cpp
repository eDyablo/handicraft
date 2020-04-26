#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  using namespace std;
  transform(istream_iterator<string>(cin), istream_iterator<string>(),
    ostream_iterator<size_t>(cout, " "),
    mem_fn(&string::size));
  cout << endl << flush;
  return 0;
}
