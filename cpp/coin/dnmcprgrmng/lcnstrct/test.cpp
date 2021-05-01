#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(lcntstrct, correctness) {
  EXPECT_THAT(all_construct("hello", {"cat", "dog"}), IsEmpty());
  EXPECT_THAT(all_construct("", {"cat", "dog"}), ElementsAre(word_bank_t{}));
  EXPECT_THAT(all_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              ElementsAre(word_bank_t{"le", "purp"},
                          word_bank_t{"le", "p", "ur", "p"}));
  EXPECT_THAT(
      all_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}),
      ElementsAre(word_bank_t{"ef", "cd", "ab"}, word_bank_t{"def", "c", "ab"},
                  word_bank_t{"def", "abc"}, word_bank_t{"ef", "abcd"}));
}
