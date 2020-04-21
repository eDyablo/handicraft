#include "evaluator.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

double evaluate(char const* expression) {
  using namespace std;
  using namespace calc;
  return evaluate(parse(tokenize(
    &expression[0], &expression[strlen(expression)])));
}

int main(int argc, char const* argv[]) {
  using namespace std;
  stringstream input;
  transform(&argv[1], &argv[argc],
    ostream_iterator<double>(cout, " "), evaluate);
  cout << endl;
  return 0;
}
