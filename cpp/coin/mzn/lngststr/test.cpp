#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::mzn;

TEST(lngststr, correctness) {
  auto str = longest_string(1, 1, 6);
  EXPECT_THAT(str, AllOf(Not(HasSubstr("aaa")), Not(HasSubstr("bbb")),
                         Not(HasSubstr("ccc"))));
}
