#include <algorithm>
#include <cmath>

namespace coin {
  namespace mzn {
    auto final_instances(size_t instances, std::vector<size_t> utilizations) {
      using namespace std;
      for (size_t i = 0; i < size(utilizations); ++i) {
        if (utilizations[i] < 25 and 1 < instances) {
          instances = ceil(instances / 2.0f);
          i += 10;
        } else if (60 < utilizations[i]) {
          instances *= 2;
          i += 10;
        }
      }
      return instances;
    }
  }  // namespace mzn
}  // namespace coin
