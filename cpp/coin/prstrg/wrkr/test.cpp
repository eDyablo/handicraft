#include <gmock/gmock.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace ::coin::prstrg;
using namespace ::std;
using namespace ::testing;

TEST(wrkr, correcteness) {
  auto worker = worker_t{[]() {}};
  worker.start([](size_t) {});
  EXPECT_THAT(0, Eq(0));
}

TEST(wrks, DISABLED_multiworker) {
  auto worker = multiworker_t();
  bool completed = false;
  worker.add([]() { cout << "first\n"; });
  worker.add([]() { cout << "second\n"; });
  worker.add([]() { cout << "third\n"; });
  worker.add([]() { cout << "fourth\n"; });
  worker.add([]() { cout << "fifth\n"; });
  worker.start([&completed](size_t id) {
    cout << "all done (" << id << ")" << endl << flush;
    completed = true;
  });
  size_t count = 10000;
  while (not completed and --count > 0) {
    this_thread::sleep_for(chrono::milliseconds(1));
  }
  cout << endl;
}
