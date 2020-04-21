#include "parser.hpp"
#include "tokenizer.hpp"
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const* argv[]) {
  using namespace std;
  using namespace calc;
  if (argc > 1) {
    cout << argv[1] << "\n";

    auto tokens = vector<token_t<char>>();
    tokenize(&argv[1][0], &argv[1][strlen(argv[1])],
      back_inserter(tokens));

    tokenize(&argv[1][0], &argv[1][strlen(argv[1])],
      std::ostream_iterator<token_t<char>>(cout, " "));
      
    cout << endl;

    auto tree = parse(tokens.cbegin(), tokens.cend());
    cout << tree << endl;
  }
  return 0;
}
