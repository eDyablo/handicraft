#include "prefix_table.hpp"

#include <gmock/gmock.h>

using namespace ::coin::prfxtbl;
using namespace ::testing;

TEST(prefix_table, is_empty_for_empty_string) {
  EXPECT_THAT(make(""), IsEmpty());
}
