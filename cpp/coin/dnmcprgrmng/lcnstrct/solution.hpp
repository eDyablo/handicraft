#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using text_t = std::string;
    using word_t = std::string;
    using word_bank_t = std::vector<word_t>;
    using combination_set_t = std::vector<word_bank_t>;

    combination_set_t all_construct(text_t const& text,
                                    word_bank_t const& word_bank) {
      using namespace std;
      if (text.empty()) return combination_set_t{word_bank_t{}};
      combination_set_t combinations;
      for (auto word : word_bank) {
        if (text.find(word) == 0) {
          auto const reminder = text.substr(word.size());
          auto reminder_combinations = all_construct(reminder, word_bank);
          if (not reminder_combinations.empty()) {
            for (auto& words : reminder_combinations) {
              words.push_back(word);
            }
            move(begin(reminder_combinations), end(reminder_combinations),
                 back_inserter(combinations));
          }
        }
      }
      return combinations;
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
