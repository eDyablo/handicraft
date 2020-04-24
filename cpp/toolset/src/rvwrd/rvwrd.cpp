#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

template<typename Container>
auto reversed(Container const& origin) {
  using namespace std;
  auto result = Container();
  reverse_copy(origin.cbegin(), origin.cend(), back_inserter(result));
  return result;
}

int main() {
  using namespace std;
  transform(istream_iterator<string>(cin), istream_iterator<string>(),
    ostream_iterator<string>(cout, " "),
    bind(reversed<string>, placeholders::_1));
  cout << endl << flush;
  return 0;
}
