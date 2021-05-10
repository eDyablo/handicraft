#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::dnmcprgrmng;

TEST(cntsm_brtfrc, correctness) {
  using namespace brtfrc;
  EXPECT_THAT(count_sum(0, {1, 2, 3}), Eq(1));
  EXPECT_THAT(count_sum(1, {1}), Eq(1));
  EXPECT_THAT(count_sum(1, {2}), Eq(0));
  EXPECT_THAT(count_sum(2, {1, 2}), Eq(2));
  EXPECT_THAT(count_sum(3, {1, 2, 3}), Eq(3));
  EXPECT_THAT(count_sum(6, {1, 5}), Eq(2));
  EXPECT_THAT(count_sum(9, {5}), Eq(0));
  EXPECT_THAT(count_sum(10, {1, 5, 10, 25}), Eq(4));
  EXPECT_THAT(count_sum(25, {1, 5, 10, 25}), Eq(13));
  EXPECT_THAT(count_sum(7, {7, 4, 3, 2}), Eq(3));
}

TEST(cntsm_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(count_sum(0, {1, 2, 3}), Eq(1));
  EXPECT_THAT(count_sum(1, {1}), Eq(1));
  EXPECT_THAT(count_sum(1, {2}), Eq(0));
  EXPECT_THAT(count_sum(2, {1, 2}), Eq(2));
  EXPECT_THAT(count_sum(3, {1, 2, 3}), Eq(3));
  EXPECT_THAT(count_sum(6, {1, 5}), Eq(2));
  EXPECT_THAT(count_sum(9, {5}), Eq(0));
  EXPECT_THAT(count_sum(10, {1, 5, 10, 25}), Eq(4));
  EXPECT_THAT(count_sum(25, {1, 5, 10, 25}), Eq(13));
  EXPECT_THAT(count_sum(7, {7, 4, 3, 2}), Eq(3));
}

TEST(cntsm_mztn, performance) {
  using namespace mztn;
  EXPECT_THAT(count_sum(1000, number_bank_t(10, 3)), Eq(0));
}

TEST(cntsm_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(count_sum(0, {1, 2, 3}), Eq(1));
  EXPECT_THAT(count_sum(1, {1}), Eq(1));
  EXPECT_THAT(count_sum(1, {2}), Eq(0));
  EXPECT_THAT(count_sum(2, {1, 2}), Eq(2));
  EXPECT_THAT(count_sum(3, {1, 2, 3}), Eq(3));
  EXPECT_THAT(count_sum(6, {1, 5}), Eq(2));
  EXPECT_THAT(count_sum(9, {5}), Eq(0));
  EXPECT_THAT(count_sum(10, {1, 5, 10, 25}), Eq(4));
  EXPECT_THAT(count_sum(25, {1, 5, 10, 25}), Eq(13));
  EXPECT_THAT(count_sum(7, {7, 4, 3, 2}), Eq(3));
}

TEST(cntsm_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(count_sum(1000, number_bank_t(10, 3)), Eq(0));
}
