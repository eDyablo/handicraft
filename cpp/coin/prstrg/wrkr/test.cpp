#include <gmock/gmock.h>

#include <iostream>

#include "solution.hpp"

using namespace ::coin::prstrg;
using namespace ::std;
using namespace ::testing;

TEST(wrkr, correcteness) {
  auto worker = worker_t{[]() {}};
  worker.start([]() {});
  EXPECT_THAT(0, Eq(0));
}

TEST(wrks, multiworker) {
  auto worker = multiworker_t();
  worker.add([]() { cout << "first" << endl; });
  worker.add([]() { cout << "second" << endl; });
  worker.start([] { cout << "all done" << endl; });
}
