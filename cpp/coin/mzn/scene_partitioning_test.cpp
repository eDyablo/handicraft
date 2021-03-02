#include "scene_partitioning.hpp"

#include <gmock/gmock.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace ::coin::mzn;
using namespace ::std;
using namespace ::testing;

auto make_chars(std::string const& str) {
  return std::vector<char>(begin(str), end(str));
}

TEST(mzn, split_up_scenes) {
  EXPECT_THAT(split_up_scenes(make_chars("ababcbacadefegdehijhklij")),
              ElementsAreArray({9, 7, 8}));
  EXPECT_THAT(split_up_scenes(make_chars("abc")), ElementsAreArray({1, 1, 1}));
  EXPECT_THAT(split_up_scenes(make_chars("abca")), ElementsAreArray({4}));
  EXPECT_THAT(split_up_scenes<char>({}), ElementsAreArray<int>({}));
}
