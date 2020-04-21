#include "evaluator.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

int main(int argc, char const* argv[]) {
  using namespace std;
  using namespace calc;
  stringstream input;
  copy(&argv[1], &argv[argc], ostream_iterator<char const*>(input));
  input.seekp(0);
  cout << evaluate(parse(tokenize(
    istream_iterator<char>(input), istream_iterator<char>()))) << endl;
  return 0;
}
