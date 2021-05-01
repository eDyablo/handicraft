#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    using word_t = std::string;
    using text_t = std::string;
    using word_set_t = std::vector<word_t>;
    using can_construct_memo_t = std::unordered_map<text_t, bool>;

    /**
     * m = text length
     * n = words count
     *
     * Brute force:
     * time:   O(n^m * m) == O(n^m)
     * memory: O(m^2)
     *
     * Memoized version:
     * time:   O(n * m^2)
     * memory: O(m^2)
     **/
    bool can_construct(text_t const& text, word_set_t const& word_bank,
                       can_construct_memo_t& memo) {
      if (memo.find(text) != memo.end()) return memo[text];
      if (empty(text)) return true;
      for (auto word : word_bank) {
        if (text.find(word) == 0) {
          auto const reminder = text.substr(size(word));
          if (can_construct(reminder, word_bank, memo)) {
            memo[text] = true;
            return true;
          }
        }
      }
      memo[text] = false;
      return false;
    }

    bool can_construct(text_t const& text, word_set_t const& words) {
      can_construct_memo_t memo;
      return can_construct(text, words, memo);
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
