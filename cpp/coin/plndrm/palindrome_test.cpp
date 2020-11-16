#include "palindrome.hpp"

#include <gmock/gmock.h>

using namespace ::coin::plndrm;
using namespace ::testing;

TEST(is_palindrome, returns_true_for_empty_string) {
  EXPECT_THAT(is_palindrome(""), Eq(true));
}
