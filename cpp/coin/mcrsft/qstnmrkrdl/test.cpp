#include "solution.hpp"

#include <gmock/gmock.h>

#include <string>

using namespace ::coin::mcrsft;
using namespace ::std;
using namespace ::testing;

TEST(qstnmrkrdl, correctness) {
  auto riddles = {
      string(""),
      string("?"),
      string("??"),
      string("???"),
      string("abc"),
      string("a?"),
      string("ab?"),
      string("?a"),
      string("??a"),
      string("??b"),
      string("??c"),
      string("a?a"),
      string("a?b"),
      string("a?c"),
      string("a?a?a"),
      string("a?a?b"),
      string("a?b?b"),
      string("a?b?c"),
      string("?a?b??c???d????"),
      string(13, '?'),
      string(14, '?'),
      string(26, '?'),
  };
  for (auto riddle : riddles) {
    auto const answer = replace_question_marks(riddle);
    EXPECT_THAT(answer, AllOf(Each(Not('?')), Each(Ge('a')), Each(Le('z'))));
    EXPECT_THAT(adjacent_find(begin(answer), end(answer)), Eq(end(answer)));
  }
}

TEST(qstnmrkrdl, performance) {
  replace_question_marks(string(1'000'000, '?'));
}
