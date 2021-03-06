#include "solution.hpp"

#include <gmock/gmock.h>

using namespace ::coin::mzn;
using namespace ::testing;
using namespace ::std;

TEST(fvstrslrs, correctness) {
  EXPECT_THAT(reviews_needed(vector<review_t>({{4, 4}, {1, 2}, {3, 6}}), 77),
              Eq(3));
}
