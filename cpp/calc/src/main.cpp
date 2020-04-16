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
    auto tokenizer = tokenizer_t<char>();
    auto tokens = vector<token_t<char>>();

    tokenizer.tokenize(&argv[1][0], &argv[1][strlen(argv[1])],
      back_inserter(tokens));

    tokenizer.tokenize(&argv[1][0], &argv[1][strlen(argv[1])],
      std::ostream_iterator<token_t<char>>(cout, " "));

    cout << endl;
  }
  return 0;
}
