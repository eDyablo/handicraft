#pragma once

#include <string>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using text_t = std::string;
    using word_t = std::string;
    using word_bank_t = std::vector<word_t>;

    size_t count_construct(text_t const& text, word_bank_t const& word_bank) {
      if (text.empty()) return 1;
      size_t count = 0;
      for (auto word : word_bank) {
        if (text.find(word) == 0) {
          auto const reminder = text.substr(word.size());
          count += count_construct(reminder, word_bank);
        }
      }
      return count;
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
