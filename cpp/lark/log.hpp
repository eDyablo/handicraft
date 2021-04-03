#pragma once

#include <string>

namespace lark {
  struct log_t {
    using text_t = std::string;
    
    virtual void record(text_t const& text) = 0;
  };
}  // namespace lark
