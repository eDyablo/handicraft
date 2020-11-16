#include "palindrome.hpp"

#include <gmock/gmock.h>

using namespace ::coin::plndrm;
using namespace ::testing;

TEST(is_palindrome, returns_true_for_empty_string) {
  EXPECT_THAT(is_palindrome(""), Eq(true));
}

TEST(is_palindrome, returns_flase_for_string_of_two_different_letters) {
  EXPECT_THAT(is_palindrome("ab"), Eq(false));
}

TEST(is_palindrome, returns_true_for_one_letter_string) {
  EXPECT_THAT(is_palindrome("a"), Eq(true));
}

TEST(is_palindrome, returns_true_for_string_of_two_equal_letters) {
  EXPECT_THAT(is_palindrome("aa"), Eq(true));
}

TEST(is_palindrome, returns_false_for_three_letters_string_when_two_first_letters_are_equal) {
  EXPECT_THAT(is_palindrome("aab"), Eq(false));
}
