#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(cntcnstrct, correctness) {
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

TEST(DISABLED_cntcnstrct, performance) {
  EXPECT_THAT(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(0));
}
