#include <algorithm>
#include <cctype>
#include <functional>
#include <iosfwd>
#include <iterator>
#include <map>
#include <vector>

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

  char const* description() const {
    static const auto map = std::map<token_kind, char const*> {
      { unknown, "unknown" },
      { unrecognized, "unrecognized" },
      { number, "number" },
      { operation, "operation" },
      { open_bracket, "open_bracket" },
      { close_bracket, "close_bracket" },
      { whitespace, "whitespace" },
    };
    return map.at(kind);
  }

  bool is_number() const {
    return kind == number;
  }

  void append(symbol_t const& symbol) {
    symbols.push_back(symbol);
  }

  template <typename>
  friend std::ostream& operator<<(std::ostream& stream, token_t const& token);
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

template <typename C>
struct tokenizer_t {
  typedef C symbol_t;
  typedef struct token_t<symbol_t> token_t;

  static std::map<symbol_t, token_kind> symbol_to_token;

  static token_kind kind_of(symbol_t const& symbol) {
    auto const& found = symbol_to_token.find(symbol);
    return found != symbol_to_token.end() ? (*found).second : unrecognized;
  }

  template<typename InputIterator, typename OutputIterator>
  void tokenize(InputIterator first, InputIterator last, OutputIterator result) {
    auto token = token_t();
    for (auto iter = first; iter != last; ++iter) {
      auto const& symbol = *iter;
      auto const kind = kind_of(symbol);
      if (unknown == token.kind) {
        token = token_t { kind, { symbol } };
      } else if (kind == token.kind) {
        token.append(symbol);
      } else {
        *result = token;
        token = token_t { kind, { symbol } };
      }
    }
    *result = token;
  }
};

template<typename C>
std::map<typename tokenizer_t<C>::symbol_t, token_kind> tokenizer_t<C>::symbol_to_token = {
  { symbol_t('0'), number },
  { symbol_t('1'), number },
  { symbol_t('2'), number },
  { symbol_t('3'), number },
  { symbol_t('4'), number },
  { symbol_t('5'), number },
  { symbol_t('6'), number },
  { symbol_t('7'), number },
  { symbol_t('8'), number },
  { symbol_t('9'), number },
  { symbol_t('.'), number },
  { symbol_t('+'), operation },
  { symbol_t('-'), operation },
  { symbol_t('*'), operation },
  { symbol_t('/'), operation },
  { symbol_t('('), open_bracket },
  { symbol_t(')'), close_bracket },
  { symbol_t(' '), whitespace },
  { symbol_t('\t'), whitespace },
};
