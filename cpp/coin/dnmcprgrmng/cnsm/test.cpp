#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(cnsm_brtfrc, correctness) {
  using namespace brtfrc;
  EXPECT_THAT(can_sum(0, {}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 3}), Eq(true));
  EXPECT_THAT(can_sum(7, {5, 3, 4, 7}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 4}), Eq(false));
  EXPECT_THAT(can_sum(8, {2, 3, 5}), Eq(true));
}

TEST(cnsm_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(can_sum(0, {}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 3}), Eq(true));
  EXPECT_THAT(can_sum(7, {5, 3, 4, 7}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 4}), Eq(false));
  EXPECT_THAT(can_sum(8, {2, 3, 5}), Eq(true));
}

TEST(cnsm_mztn, performance) {
  using namespace mztn;
  EXPECT_THAT(can_sum(300, {7, 14}), Eq(false));
}

TEST(cnsm_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(can_sum(0, {1, 2, 3}), Eq(true));
  EXPECT_THAT(can_sum(1, {1}), Eq(true));
  EXPECT_THAT(can_sum(3, {1, 2}), Eq(true));
  EXPECT_THAT(can_sum(1, {10}), Eq(false));
  EXPECT_THAT(can_sum(7, {5, 3, 4}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 3}), Eq(true));
  EXPECT_THAT(can_sum(7, {5, 3, 4, 7}), Eq(true));
  EXPECT_THAT(can_sum(7, {2, 4}), Eq(false));
  EXPECT_THAT(can_sum(8, {2, 3, 5}), Eq(true));
}

TEST(cnsm_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(can_sum(300, {7, 14}), Eq(false));
}
