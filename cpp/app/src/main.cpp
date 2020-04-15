#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <functional>

class Parser {
  State* state;

public:
  void setState(State& state);

  void symbol(char symbol);
};

class State {
public:
  static State& SIMPLE;

  virtual void symbol(char symbol, Parser& parser) = 0;
};

class html_element_finder {
private:
  std::istream& stream;

public:
  html_element_finder(std::istream& stream)
    : stream(stream)
  {
  }

  void find_by_id(std::string const& id) {
    stream >> std::noskipws;
    auto input_iter = std::istream_iterator<char>(stream);
    auto input_end = std::istream_iterator<char>();
    auto parser = Parser();
    std::for_each(input_iter, input_end, 
      std::bind(&html_element_finder::process, this, std::placeholders::_1));
  }

  void process(char symbol) {
    if (symbol == '<') {
      found_tag_open(symbol);
    } else if (symbol == '>') {
      found_tag_close(symbol);
    } else {
      std::cout << symbol;
    }
  }

  void found_tag_open(char symbol) {
  }

  void found_tag_close(char symbol) {
  }
};

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    auto input = std::ifstream(argv[1]);
    auto finder = html_element_finder(input);
    finder.find_by_id("make-everything-ok-button");
  }
  if (argc > 2) {
    std::cout << argv[2] << std::endl;
  }
  return 0;
}
