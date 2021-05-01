#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(fbnc, correctness) {
  EXPECT_THAT(fibo(1), Eq(1));
  EXPECT_THAT(fibo(2), Eq(1));
  EXPECT_THAT(fibo(3), Eq(2));
  EXPECT_THAT(fibo(4), Eq(3));
  EXPECT_THAT(fibo(5), Eq(5));
  EXPECT_THAT(fibo(6), Eq(8));
  EXPECT_THAT(fibo(7), Eq(13));
  EXPECT_THAT(fibo(8), Eq(21));
  EXPECT_THAT(fibo(9), Eq(34));
}

TEST(fbnc, performance) {
  EXPECT_THAT(fibo(50), Eq(12'586'269'025));
}
