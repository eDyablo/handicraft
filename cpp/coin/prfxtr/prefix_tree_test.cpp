#include "prefix_tree.hpp"

#include <gmock/gmock.h>

using namespace ::coin::prfxtr;
using namespace ::testing;

TEST(tree, has_two_nodes_when_one_letter_inserted) {
  tree_t<char> tree;
  tree.insert("a");
  EXPECT_THAT(tree.node_count(), Eq(2));
}
