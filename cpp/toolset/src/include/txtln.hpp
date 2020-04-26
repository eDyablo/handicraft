#pragma once

#include <iosfwd>
#include <string>

template<typename CharT>
struct basic_line_t {
  typedef basic_line_t self;
  typedef CharT char_t;
  typedef std::basic_string<char_t> text_t;
  typedef std::basic_istream<char_t> istream_t;
  typedef std::basic_ostream<char_t> ostream_t;

  text_t text;

  text_t const& str() const {
    return text;
  }

  friend istream_t& operator>>(istream_t& input, basic_line_t& line) {
    std::getline(input, line.text, '\n');
    return input;
  }
};

typedef basic_line_t<char> line_t;
