#include <gmock/gmock.h>

#include <iostream>

#include "solution.hpp"

using namespace ::coin::mcrsft;
using namespace ::std;
using namespace ::testing;

TEST(cmnmngr, correctness) {
  node_t ic[] = {node_t{"ic0"}, node_t{"ic1"}, node_t{"ic2"}, node_t{"ic3"}};
  node_t gm[] = {node_t{"gm0", {&ic[0], &ic[1]}}, node_t{"gm1", {&ic[2]}},
                 node_t{"gm2", {&ic[3]}}};
  auto vp = node_t{"vp", {&gm[0], &gm[1], &gm[2]}};
  cout << "resursion:  " << vp << endl;
  cout << "in depth:   ";
  vp.dump_depth(cout);
  cout << endl;
  cout << "in breadth: ";
  vp.dump_breadth(cout);
  cout << endl;
  cout << "in depth2:  ";
  vp.dump_depth2(cout);
  cout << endl;
  cout << "vp -> gm0:  " << vp.path_to("gm0") << endl;
  cout << "vp -> ic0:  " << vp.path_to("ic0") << endl;
  cout << "vp -> ic1:  " << vp.path_to("ic1") << endl;
  cout << "vp -> ic2:  " << vp.path_to("ic2") << endl;
  cout << "vp -> ic3:  " << vp.path_to("ic3") << endl;
  EXPECT_THAT(gm[0].has_child("ic0"), Eq(true));
  EXPECT_THAT(gm[0].has_child("ic1"), Eq(true));
  EXPECT_THAT(gm[1].has_child("ic2"), Eq(true));
  EXPECT_THAT(gm[1].has_child("ic0"), Eq(false));
  EXPECT_THAT(gm[2].has_child("ic3"), Eq(true));
  EXPECT_THAT(gm[2].has_child("ic1"), Eq(false));
  EXPECT_THAT(vp.has_child("gm0"), Eq(true));
  EXPECT_THAT(vp.has_child("gm1"), Eq(true));
  EXPECT_THAT(vp.has_child("gm2"), Eq(true));
  EXPECT_THAT(gm[0].find_common("ic0", "ic1"), Eq("gm0"));
  EXPECT_THAT(gm[1].find_common("ic0", "ic1"), IsEmpty());
  EXPECT_THAT(vp.find_common("ic0", "ic1"), Eq("gm0"));
  EXPECT_THAT(vp.find_common("ic0", "ic2"), Eq("vp"));
  EXPECT_THAT(vp.find_common("ic0", "gm0"), Eq("vp"));
  EXPECT_THAT(vp.find_common("gm0", "ic1"), Eq("vp"));
}
