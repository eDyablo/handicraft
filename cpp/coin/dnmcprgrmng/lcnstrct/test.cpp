#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(lcntstrct_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(all_construct("hello", {"cat", "dog"}), IsEmpty());
  EXPECT_THAT(all_construct("", {"cat", "dog"}), ElementsAre(word_bank_t{}));
  EXPECT_THAT(all_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              ElementsAre(word_bank_t{"purp", "le"},
                          word_bank_t{"p", "ur", "p", "le"}));
  EXPECT_THAT(
      all_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}),
      ElementsAre(word_bank_t{"ab", "cd", "ef"}, word_bank_t{"ab", "c", "def"},
                  word_bank_t{"abc", "def"}, word_bank_t{"abcd", "ef"}));
  EXPECT_THAT(all_construct("skateboard",
                            {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              IsEmpty());
}

TEST(lcntstrct_mztn, perfomance) {
  using namespace mztn;
  EXPECT_THAT(all_construct("aaaaaaaaaaaaaaaaaaaaaaaaaz",
                            {"a", "aa", "aaa", "aaaa", "aaaaa"}),
              IsEmpty());
}

TEST(lcntstrct_mztn, DISABLED_worst_case_performance) {
  using namespace mztn;
  EXPECT_THAT(all_construct("aaaaaaaaaaaaaaaaaaaaaaaaa",
                            {"a", "aa", "aaa", "aaaa", "aaaaa"}),
              Not(IsEmpty()));
}

TEST(lcntstrct_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(all_construct("hello", {"cat", "dog"}), IsEmpty());
  EXPECT_THAT(all_construct("", {"cat", "dog"}), ElementsAre(word_bank_t{}));
  EXPECT_THAT(all_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              ElementsAre(word_bank_t{"purp", "le"},
                          word_bank_t{"p", "ur", "p", "le"}));
  EXPECT_THAT(
      all_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}),
      UnorderedElementsAre(
          word_bank_t{"ab", "cd", "ef"}, word_bank_t{"ab", "c", "def"},
          word_bank_t{"abc", "def"}, word_bank_t{"abcd", "ef"}));
  EXPECT_THAT(all_construct("skateboard",
                            {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              IsEmpty());
  EXPECT_THAT(all_construct("aaaaaaaaaaz", {"a", "aa", "aaa", "aaaa", "aaaaa"}),
              IsEmpty());
}
