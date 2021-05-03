#include <gmock/gmock.h>

#include "solution.hpp"

using namespace ::coin::dnmcprgrmng;
using namespace ::testing;

TEST(bstsm_mztn, correctenss) {
  using namespace mztn;
  EXPECT_THAT(best_sum(7, {5, 3, 4, 7}), ElementsAre(7));
  EXPECT_THAT(best_sum(8, {2, 3, 5}), ElementsAre(5, 3));
  EXPECT_THAT(best_sum(8, {1, 4, 5}), ElementsAre(4, 4));
}

TEST(bstsm_mztn, performance) {
  using namespace mztn;
  EXPECT_THAT(best_sum(100, {1, 2, 5, 25}), ElementsAre(25, 25, 25, 25));
}

TEST(bstsm_tbltn, correctenss) {
  using namespace tbltn;
  EXPECT_THAT(best_sum(7, {5, 3, 4, 7}), ElementsAre(7));
  EXPECT_THAT(best_sum(8, {2, 3, 5}), ElementsAre(5, 3));
  EXPECT_THAT(best_sum(8, {1, 4, 5}), ElementsAre(4, 4));
}

TEST(bstsm_tbltn, performance) {
  using namespace tbltn;
  EXPECT_THAT(best_sum(100, {1, 2, 5, 25}), ElementsAre(25, 25, 25, 25));
}
