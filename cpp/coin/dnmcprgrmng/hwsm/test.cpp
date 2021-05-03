#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(hwsm_mztn, correctness) {
  using namespace mztn;
  EXPECT_THAT(how_sum(0, {1, 2, 3}), IsEmpty());
  EXPECT_THAT(how_sum(1, {1}), ElementsAre(1));
  EXPECT_THAT(how_sum(2, {1, 1}), ElementsAre(1, 1));
  EXPECT_THAT(how_sum(2, {1}), ElementsAre(1, 1));
  EXPECT_THAT(how_sum(7, {2, 3}), ElementsAre(3, 2, 2));
  EXPECT_THAT(how_sum(7, {5, 3, 4, 7}), ElementsAre(4, 3));
  EXPECT_THAT(how_sum(7, {2, 4}), IsEmpty());
  EXPECT_THAT(how_sum(8, {2, 3, 5}), ElementsAre(2, 2, 2, 2));
}

TEST(hwsm_mztn, performance) {
  using namespace mztn;
  EXPECT_THAT(how_sum(300, {7, 14}), IsEmpty());
}

TEST(hwsm_tbltn, correctness) {
  using namespace tbltn;
  EXPECT_THAT(how_sum(0, {1, 2, 3}), IsEmpty());
  EXPECT_THAT(how_sum(1, {1}), ElementsAre(1));
  EXPECT_THAT(how_sum(2, {1}), ElementsAre(1, 1));
  EXPECT_THAT(how_sum(2, {1, 1}), ElementsAre(1, 1));
  EXPECT_THAT(how_sum(7, {2, 3}), ElementsAre(3, 2, 2));
  EXPECT_THAT(how_sum(7, {5, 3, 4, 7}), ElementsAre(4, 3));
  EXPECT_THAT(how_sum(7, {2, 4}), IsEmpty());
  EXPECT_THAT(how_sum(8, {2, 3, 5}), ElementsAre(2, 2, 2, 2));
}

TEST(hwsm_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(how_sum(300, {7, 14}), IsEmpty());
}
