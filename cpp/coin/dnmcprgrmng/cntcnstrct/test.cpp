#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(cntcnstrct_brtfrc, correctness) {
  using namespace brtfrc;
  EXPECT_THAT(count_construct("", {"a", "ab", "abc"}), Eq(1));
  EXPECT_THAT(count_construct("abc", {"a", "b", "c", "ab", "bc", "abc"}),
              Eq(4));
  EXPECT_THAT(count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}),
              Eq(1));
  EXPECT_THAT(count_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              Eq(2));
  EXPECT_THAT(count_construct("skateboard",
                              {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              Eq(0));
  EXPECT_THAT(count_construct("enterapotentpot",
                              {"a", "p", "ent", "enter", "ot", "o", "t"}),
              Eq(4));
}

TEST(cntcnstrct_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(count_construct("", {"a", "ab", "abc"}), Eq(1));
  EXPECT_THAT(count_construct("abc", {"a", "b", "c", "ab", "bc", "abc"}),
              Eq(4));
  EXPECT_THAT(count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}),
              Eq(1));
  EXPECT_THAT(count_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              Eq(2));
  EXPECT_THAT(count_construct("skateboard",
                              {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              Eq(0));
  EXPECT_THAT(count_construct("enterapotentpot",
                              {"a", "p", "ent", "enter", "ot", "o", "t"}),
              Eq(4));
}

TEST(cntcnstrct_mzn, performance) {
  using namespace mztn;
  EXPECT_THAT(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(0));
  EXPECT_THAT(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(437513522));
}

TEST(cntcnstrct_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(count_construct("", {"a"}), Eq(1));
  EXPECT_THAT(count_construct("a", {"a"}), Eq(1));
  EXPECT_THAT(count_construct("a", {"b"}), Eq(0));
  EXPECT_THAT(count_construct("a", {"a", "a"}), Eq(2));
  EXPECT_THAT(count_construct("ab", {"a"}), Eq(0));
  EXPECT_THAT(count_construct("ab", {"b", "b"}), Eq(0));
  EXPECT_THAT(count_construct("aa", {"a", "a"}), Eq(4));
  EXPECT_THAT(count_construct("abc", {"a", "b", "c", "ab", "bc", "abc"}),
              Eq(4));
  EXPECT_THAT(count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}),
              Eq(1));
  EXPECT_THAT(count_construct("purple", {"purp", "p", "ur", "le", "purpl"}),
              Eq(2));
  EXPECT_THAT(count_construct("skateboard",
                              {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              Eq(0));
  EXPECT_THAT(count_construct("enterapotentpot",
                              {"a", "p", "ent", "enter", "ot", "o", "t"}),
              Eq(4));
}

TEST(cntcnstrct_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(0));
  EXPECT_THAT(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(437513522));
}
