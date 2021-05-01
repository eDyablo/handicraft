#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(lcntstrct, correctness) {
  EXPECT_THAT(all_construct("hello", {"cat", "dog"}), IsEmpty());
  EXPECT_THAT(all_construct("", {"cat", "dog"}), ElementsAre(word_bank_t{}));
  EXPECT_THAT(all_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              ElementsAre(word_bank_t{"purp", "le"},
                          word_bank_t{"p", "ur", "p", "le"}));
  EXPECT_THAT(
      all_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}),
      ElementsAre(word_bank_t{"ab", "cd", "ef"}, word_bank_t{"ab", "c", "def"},
                  word_bank_t{"abc", "def"}, word_bank_t{"abcd", "ef"}));
}
