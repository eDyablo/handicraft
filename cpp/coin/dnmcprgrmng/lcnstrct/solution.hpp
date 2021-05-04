#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using text_t = std::string;
    using word_t = std::string;
    using word_bank_t = std::vector<word_t>;
    using combination_set_t = std::vector<word_bank_t>;

    namespace mztn {
      using all_construct_memo_t =
          std::unordered_map<text_t, combination_set_t>;

      /**
       * m = text length
       * n = word count
       *
       * Memoized solution:
       * O(n^m)
       * O(m)
       */
      combination_set_t all_construct(text_t const& text,
                                      word_bank_t const& word_bank,
                                      all_construct_memo_t& memo) {
        using namespace std;
        if (memo.find(text) != memo.end()) return memo[text];
        if (text.empty()) return combination_set_t{word_bank_t{}};
        combination_set_t combinations;
        for (auto word : word_bank) {
          if (text.find(word) == 0) {
            auto const reminder = text.substr(word.size());
            auto reminder_combinations =
                all_construct(reminder, word_bank, memo);
            for (auto& words : reminder_combinations) {
              words.push_back(word);
            }
            move(begin(reminder_combinations), end(reminder_combinations),
                 back_inserter(combinations));
          }
        }
        memo[text] = combinations;
        return combinations;
      }

      combination_set_t all_construct(text_t const& text,
                                      word_bank_t const& word_bank) {
        using namespace std;
        all_construct_memo_t memo;
        auto combinations = all_construct(text, word_bank, memo);
        for (auto& combination : combinations) {
          reverse(begin(combination), end(combination));
        }
        return combinations;
      }
    }  // namespace mztn

    namespace tbltn {
      using all_construct_table_t = std::vector<combination_set_t>;

      /**
       * m = text length
       * n = word count
       *
       * Tabulated solution:
       * O(n^m)
       * O(n^m)
       */
      combination_set_t all_construct(text_t const& text,
                                      word_bank_t const& word_bank) {
        using namespace std;
        all_construct_table_t table(text.size() + 1);
        table[0] = combination_set_t{word_bank_t{}};
        for (size_t position = 0; position < text.size(); ++position) {
          if (not table[position].empty()) {
            auto const reminder = text.substr(position);
            for (auto const& word : word_bank) {
              if (reminder.find(word) == 0) {
                auto combination = table[position];
                for (auto& words : combination) {
                  words.push_back(word);
                }
                move(begin(combination), end(combination),
                     back_inserter(table[position + word.size()]));
              }
            }
          }
        }
        return table[text.size()];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
