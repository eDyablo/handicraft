#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::mzn;
using namespace ::std;
using namespace ::testing;

TEST(tlztnchcks, correctness) {
  EXPECT_THAT(final_instances(1, {5, 10, 80}), Eq(2));
  EXPECT_THAT(final_instances(5, {30, 5, 4, 8, 19, 89}), Eq(3));
  EXPECT_THAT(
      final_instances(2, {25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80}),
      Eq(2));
}

TEST(tlztnchcks, performance) {
  final_instances(100000, vector<size_t>(100000, 50));
}
