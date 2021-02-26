#include "microsoft.hpp"

#include <gmock/gmock.h>

#include <algorithm>
#include <vector>

using namespace ::coin::microsoft;
using namespace ::std;
using namespace ::testing;

TEST(microsoft, max_sum_of_equal_digits_sum_pair) {
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 71, 17, 42}), Eq(93));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({42, 33, 60}), Eq(102));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 32, 43}), Eq(-1));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({}), Eq(-1));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({51, 71, 17, 42, 33, 80}),
              Eq(151));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({17, 33, 42, 51, 71, 80}),
              Eq(151));
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair<int>({80, 71, 51, 42, 33, 17}),
              Eq(151));
}

TEST(microsoft, DISABLED_max_sum_of_equal_digits_sum_pair_performance) {
  vector<int> numbers(200'000);
  generate(begin(numbers), end(numbers), []() -> int {
    static int counter = 1'000'000'000;
    return counter--;
  });
  EXPECT_THAT(max_sum_of_equal_digits_sum_pair(numbers), Not(Eq(-1)));
}

TEST(microsoft, replace_question_marks) {
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

TEST(microsoft, replace_question_marks_performance) {
  replace_question_marks(string(100'000, '?'));
}
