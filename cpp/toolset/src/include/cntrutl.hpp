#pragma once

#include <algorithm>
#include <iterator>

template<typename Container>
auto reversed(Container const& origin) {
  using namespace std;
  auto result = Container();
  reverse_copy(origin.cbegin(), origin.cend(), back_inserter(result));
  return result;
}
