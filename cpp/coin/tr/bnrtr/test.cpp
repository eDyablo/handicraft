#include <gmock/gmock.h>

#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace ::coin::tr;
using namespace ::std;
using namespace ::testing;

using tree_t = binary_tree<string>;
using node_t = tree_t::node_t;

struct bnrtr : public Test {
  tree_t tree;
  vector<node_t> nodes;

  void SetUp() {
    nodes = vector<node_t>(7, node_t{});
    nodes[0] = node_t{"b1"};
    nodes[1] = node_t{"b2"};
    nodes[2] = node_t{"b3"};
    nodes[3] = node_t{"b4"};
    nodes[4] = node_t{"a1", &nodes[0], &nodes[1]};
    nodes[5] = node_t{"a2", &nodes[2], &nodes[3]};
    nodes[6] = node_t{"root", &nodes[4], &nodes[5]};
    tree = tree_t{&nodes[6]};
  }
};

TEST_F(bnrtr, in_depth) {
  vector<string> values;
  tree.in_depth(
      [&values](node_t const& node) { values.push_back(node.value); });
  EXPECT_THAT(values, ElementsAre("root", "a1", "b1", "b2", "a2", "b3", "b4"));
}

TEST_F(bnrtr, in_breadth) {
  vector<string> values;
  tree.in_breadth(
      [&values](node_t const& node) { values.push_back(node.value); });
  EXPECT_THAT(values, ElementsAre("root", "a1", "a2", "b1", "b2", "b3", "b4"));
}
