#include "tokenizer.hpp"

#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const* argv[]) {
  if (argc > 1) {
    std::cout << argv[1] << "\n";
    auto tokenizer = tokenizer_t<char>();
    auto tokens = std::vector<token_t<char>>();

    tokenizer.tokenize(&argv[1][0], &argv[1][std::strlen(argv[1])], back_inserter(tokens));

    copy(tokens.begin(), tokens.end(), std::ostream_iterator<token_t<char>>(std::cout, " "));

    std::cout << std::endl;
  }
  return 0;
}
