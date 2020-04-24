#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

template<typename C>
struct basic_line_t {
  typedef C char_t;
  typedef std::basic_string<char_t> text_t;
  typedef std::basic_istream<char_t> istream_t;
  typedef std::basic_ostream<char_t> ostream_t;

  text_t text;

  friend istream_t& operator>>(istream_t& input, basic_line_t& line) {
    std::getline(input, line.text);
    return input;
  }
};

typedef basic_line_t<char> line_t;

int main() {
  using namespace std;
  cout << accumulate(istream_iterator<line_t>(cin), istream_iterator<line_t>(),
    0, bind(plus<size_t>(), placeholders::_1, 1)) << endl;
  return 0;
}
