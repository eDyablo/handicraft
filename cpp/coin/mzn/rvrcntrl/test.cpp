#include <gmock/gmock.h>

#include <algorithm>

#include "solution.hpp"

using namespace ::coin::mzn;
using namespace ::std;
using namespace ::testing;

TEST(rvrcntrl, correctness) {
  EXPECT_THAT(move_rover(4, {"RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN"}),
              Eq(12));
  EXPECT_THAT(move_rover(4, {"RIGHT", "DOWN", "LEFT", "LEFT", "DOWN"}), Eq(8));
}

TEST(rvrcntrl, performance) {
  auto commands = programm_t{"RIGHT", "DOWN", "LEFT", "UP"};
  auto programm = programm_t(20);
  generate(begin(programm), end(programm), [&commands, n = 0]() mutable {
    return commands[(n++ % size(commands))];
  });
  move_rover(20, programm);
}
