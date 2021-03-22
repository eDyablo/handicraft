#include <gmock/gmock.h>

#include <iostream>
#include <string>

#include "solution.hpp"

using namespace ::coin::tr;
using namespace ::std;
using namespace ::testing;

TEST(bnrtr, correctness) {
  using tree_t = binary_tree<string>;
  using node_t = tree_t::node_t;
  node_t l1[] = {{"a1"}, {"a2"}};
  auto root = node_t{"root", &l1[0], &l1[1]};
  auto tree = tree_t{&root};
  tree.dump(cout);
  cout << endl;
}
