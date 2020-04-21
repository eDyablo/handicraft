#include "evaluator.hpp"
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
    cout << evaluate(parse(tokenize(&argv[1][0], &argv[1][strlen(argv[1])]))) << endl;
  }
  return 0;
}
