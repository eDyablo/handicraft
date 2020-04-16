#include <algorithm>
#include <map>
#include <vector>
#include <iterator>

namespace calc {
  enum token_kind {
    unknown,
    unrecognized,
    number,
    operation,
    open_bracket,
    close_bracket,
    whitespace,
  };

  template <typename Symbol>
  struct token_t {
    typedef Symbol symbol_t;
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

  template <typename Symbol>
  std::map<token_kind, char const*> token_t<Symbol>::kind_to_name = {
    { unrecognized, "unrecognized" },
    { number, "number" },
    { operation, "operation" },
    { open_bracket, "open_bracket" },
    { close_bracket, "close_bracket" },
    { whitespace, "whitespace" },
  };

  template <typename Symbol>
  std::ostream& operator<<(std::ostream& stream, token_t<Symbol> const& token) {
    stream << token.description();
    if (!token.symbols.empty()) {
      stream << "('";
      std::copy(token.symbols.cbegin(), token.symbols.cend(), std::ostream_iterator<Symbol>(stream));
      stream << "')";
    }
    return stream;
  }
}
