#include "prefix_table.hpp"

#include <gmock/gmock.h>

using namespace ::coin::prfxtbl;
using namespace ::testing;

std::vector<int> prefixFunction(std::string const& s) {
  std::vector<int> p(s.size());
  int j = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    while (j > 0 && s[j] != s[i])
      j = p[j-1];

    if (s[j] == s[i])
      j++;
    p[i] = j;
  }   
  return p;
}

TEST(prefix_table, is_empty_for_empty_string) {
  EXPECT_THAT(make(""), IsEmpty());
}

TEST(prefix_table, rename_me) {
  EXPECT_THAT(make("a"), ElementsAreArray(prefixFunction("a")));
  EXPECT_THAT(make("aa"), ElementsAreArray(prefixFunction("aa")));
  //EXPECT_THAT(make("aaa"), ElementsAreArray(prefixFunction("aaa")));
}
