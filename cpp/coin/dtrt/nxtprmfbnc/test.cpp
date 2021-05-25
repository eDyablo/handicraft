#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dtrt;

struct test_case_t {
  int number;
  int expected;
};

TEST(nxtprmfbnc, correctness) {
  test_case_t tests[] = {{0, 1},  {1, 2},   {2, 3},   {3, 5},   {4, 5},
                         {5, 13}, {13, 89}, {20, 89}, {89, 233}};
  for (auto test : tests) {
    EXPECT_THAT(next_prime_fibonacci(test.number), Eq(test.expected));
  }
}

TEST(nxtprmfbnc, performance) {
  EXPECT_THAT(next_prime_fibonacci(2'000'000'000), Eq(2'971'215'073));
}
