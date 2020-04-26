#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

template<typename C>
struct basic_line_t {
  typedef C char_t;
  typedef std::basic_string<char_t> text_t;
  typedef std::basic_istream<char_t> istream_t;
  typedef std::basic_ostream<char_t> ostream_t;

  text_t text;

  text_t const& str() const {
    return text;
  }

  friend istream_t& operator>>(istream_t& input, basic_line_t& line) {
    std::getline(input, line.text, '\n');
    return input;
  }
};

template<typename Container>
auto reversed(Container const& origin) {
  using namespace std;
  auto result = Container();
  reverse_copy(origin.cbegin(), origin.cend(), back_inserter(result));
  return result;
}

typedef basic_line_t<char> line_t;

int main() {
  using namespace std;
  transform(istream_iterator<line_t>(cin), istream_iterator<line_t>(),
    ostream_iterator<string>(cout, "\n"),
    bind(reversed<string>, bind(&line_t::str, placeholders::_1)));
  return 0;
}
