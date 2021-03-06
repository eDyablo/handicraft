#include <gmock/gmock.h>

#include <vector>

#include "solution.hpp"

using namespace ::testing;
using namespace ::coin::mzn;
using namespace ::std;

struct cluster_test_t {
  plan_t plan;
  size_t cluster_count;
};

TEST(cntclstrs, correctness) {
  vector<cluster_test_t> cases = {
      {
          {
              {0, 1, 0},
              {0, 1, 1},
              {0, 0, 0},
          },
          1,
      },
      {
          {
              {1, 0, 0},
              {0, 1, 0},
              {0, 0, 1},
          },
          3,
      },
      {
          {
              {1, 0, 1},
              {0, 1, 0},
              {1, 0, 1},
          },
          5,
      },
      {
          {
              {0, 0, 1, 0},
              {0, 1, 1, 0},
              {1, 0, 1, 1},
              {1, 0, 0, 1},
              {1, 1, 1, 1},
          },
          1,
      },
      {
          {
              {0, 0, 0, 0, 0},
              {0, 1, 0, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 1, 1, 0, 1},
              {0, 0, 0, 0, 1},
          },
          4,
      },
      {
          {
              {1, 1, 1, 1, 0, 0, 0, 0},
              {1, 0, 0, 1, 0, 0, 0, 0},
              {1, 1, 1, 1, 0, 0, 1, 0},
              {0, 0, 0, 0, 0, 1, 1, 1},
              {0, 0, 0, 0, 0, 1, 0, 1},
              {0, 0, 0, 1, 1, 1, 1, 1},
          },
          2,
      },
  };
  for (auto test : cases) {
    EXPECT_THAT(count_clusters(test.plan), Eq(test.cluster_count));
  }
}
