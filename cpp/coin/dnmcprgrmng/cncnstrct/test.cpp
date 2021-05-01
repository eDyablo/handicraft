#include <gmock/gmock.h>

#include <algorithm>
#include <iterator>

#include "solution.hpp"
using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(cncnstrct, correctness) {
  EXPECT_THAT(can_construct("", {"a", "ab", "abc"}), Eq(true));
  EXPECT_THAT(can_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}),
              Eq(true));
  EXPECT_THAT(can_construct("skateboard",
                            {"bo", "rd", "ate", "t", "ska", "sk", "boar"}),
              Eq(false));
  EXPECT_THAT(can_construct("enterapotentpot",
                            {"a", "p", "ent", "enter", "ot", "o", "t"}),
              Eq(true));
  text_t alphabet = "abcdefghijklmnopqrstuvwxyz";
  word_set_t letters;
  using namespace std;
  transform(begin(alphabet), end(alphabet), back_inserter(letters),
            [](char l) -> word_t { return word_t{l}; });
  EXPECT_THAT(can_construct(alphabet, letters), Eq(true));
}

TEST(cncnstrct, performance) {
  EXPECT_THAT(can_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                            {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}),
              Eq(false));
}
