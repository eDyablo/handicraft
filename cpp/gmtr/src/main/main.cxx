#include "point.hpp"
#include "vector.hpp"
#include "system.hpp"
#include "space.hpp"
#include <iostream>

using namespace std;
using namespace gmtr;

int main() {
  space3_t space;

  cout << point2_t() << endl;
  cout << point3_t() << endl;
  cout << vector2_t() << endl;
  cout << vector3_t() << endl;

  cout << vector3_t().dot_product(vector3_t());

  cout << endl;

  return 0;
}
