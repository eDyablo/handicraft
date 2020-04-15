#include "token.hpp"
#include <map>

template <typename Symbol>
struct tokenizer_t {
  typedef Symbol symbol_t;
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

template<typename Symbol>
std::map<typename tokenizer_t<Symbol>::symbol_t, token_kind> tokenizer_t<Symbol>::symbol_to_token = {
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
