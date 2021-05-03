#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using text_t = std::string;
    using word_t = std::string;
    using word_bank_t = std::vector<word_t>;

    namespace mztn {
      using count_construct_memo_t = std::unordered_map<text_t, size_t>;

      /**
       * m = text length
       * n = words bank size
       *
       * Brute force:
       * time:  O(n^m * m) == O(n^m)
       * space: O(m^2)
       *
       * Memoized solution:
       * time:  O(n * m^2)
       * space: O(m^2)
       **/
      size_t count_construct(text_t const& text, word_bank_t const& word_bank,
                             count_construct_memo_t& memo) {
        if (memo.find(text) != memo.end()) return memo[text];
        if (text.empty()) return 1;
        size_t count = 0;
        for (auto word : word_bank) {
          if (text.find(word) == 0) {
            auto const reminder = text.substr(word.size());
            count += count_construct(reminder, word_bank, memo);
          }
        }
        memo[text] = count;
        return count;
      }

      size_t count_construct(text_t const& text, word_bank_t const& word_bank) {
        count_construct_memo_t memo;
        return count_construct(text, word_bank, memo);
      }
    }  // namespace mztn

    namespace tbltn {
      using count_construct_table_t = std::vector<size_t>;

      /**
       * m = text length
       * n = words bank size
       * 
       * Tabulated solution:
       * time:  O(n * m^2)
       * space: O(m)
       **/
      size_t count_construct(text_t const& text, word_bank_t const& word_bank) {
        count_construct_table_t table(text.size() + 1, 0);
        table[0] = 1;
        for (size_t position = 0; position < text.size(); ++position) {
          if (table[position] > 0) {
            for (auto const& word : word_bank) {
              auto const remainder = text.substr(position);
              if (remainder.find(word) == 0) {
                table[position + word.size()] += table[position];
              }
            }
          }
        }
        return table[text.size()];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
