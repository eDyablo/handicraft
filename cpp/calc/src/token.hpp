#include <algorithm>
#include <map>
#include <vector>
#include <iterator>

enum token_kind {
  unknown,
  unrecognized,
  number,
  operation,
  open_bracket,
  close_bracket,
  whitespace,
};

template <typename C>
struct token_t {
  typedef C symbol_t;
  typedef std::vector<symbol_t> vector_t;

  token_kind kind;
  std::vector<symbol_t> symbols;

  static std::map<token_kind, char const*> kind_to_name;

  char const* description() const {
    auto const& found = kind_to_name.find(kind);
    return found != kind_to_name.end() ? (*found).second : "unknown";
  }

  void append(symbol_t const& symbol) {
    symbols.push_back(symbol);
  }

  template <typename>
  friend std::ostream& operator<<(std::ostream& stream, token_t const& token);
};

template <typename C>
std::map<token_kind, char const*> token_t<C>::kind_to_name = {
  { unrecognized, "unrecognized" },
  { number, "number" },
  { operation, "operation" },
  { open_bracket, "open_bracket" },
  { close_bracket, "close_bracket" },
  { whitespace, "whitespace" },
};

template <typename C>
std::ostream& operator<<(std::ostream& stream, token_t<C> const& token) {
  stream << token.description();
  if (!token.symbols.empty()) {
    stream << "('";
    std::copy(token.symbols.cbegin(), token.symbols.cend(), std::ostream_iterator<C>(stream));
    stream << "')";
  }
  return stream;
}
