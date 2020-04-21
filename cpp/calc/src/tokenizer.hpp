#pragma once

#include "token.hpp"
#include <functional>
#include <iterator>
#include <map>
#include <vector>

namespace calc {
  template <typename Symbol>
  struct tokenizer_t {
    typedef Symbol symbol_t;
    typedef struct token_t<symbol_t> token_t;

    static std::map<symbol_t, token_kind> symbol_to_token;
    
    static std::vector<token_kind> continuation_token_kinds;

    token_t token;

    static token_kind kind_of(symbol_t const& symbol) {
      auto const& found = symbol_to_token.find(symbol);
      return found != symbol_to_token.end() ? (*found).second : unrecognized;
    }

    token_t make_token(symbol_t const& symbol) {
      return token_t { kind_of(symbol), { symbol } };
    }

    bool is_continuation(token_t const& new_token) {
      using namespace std;
      return new_token.kind == token.kind &&
        any_of(continuation_token_kinds.cbegin(), continuation_token_kinds.cend(),
          bind(std::equal_to<token_kind>(), new_token.kind, placeholders::_1));
    }

    token_t tokenize(symbol_t const& symbol) {
      auto new_token = make_token(symbol);
      if (is_continuation(new_token)) {
        token.append(symbol);
        return token_t();
      } else {
        std::swap(token, new_token);
        return new_token;
      }
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

  template<typename Symbol>
  std::vector<token_kind> tokenizer_t<Symbol>::continuation_token_kinds = {
    number,
    whitespace,
  };

  template<typename InputIterator, typename OutputIterator>
  void tokenize(InputIterator first, InputIterator last, OutputIterator result) {
    typedef typename std::iterator_traits<InputIterator>::value_type value_t;
    auto tokenizer = tokenizer_t<value_t>();
    for (auto iter = first; iter != last; ++iter) {
      auto token = tokenizer.tokenize(*iter);
      if (unknown != token.kind) {
        *result = token;
      }
    }
    if (unknown != tokenizer.token.kind) {
      *result = tokenizer.token;
    }
  }

  template<typename InputIterator>
  auto tokenize(InputIterator first, InputIterator last) {
    typedef typename std::iterator_traits<InputIterator>::value_type value_t;
    std::vector<token_t<value_t>> tokens;
    tokenize(first, last, std::back_inserter(tokens));
    return tokens;
  }
}
