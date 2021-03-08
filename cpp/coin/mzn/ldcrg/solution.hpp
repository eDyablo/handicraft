#include <algorithm>
#include <vector>

namespace coin {
  namespace mzn {
    auto maximum_shipped_items(std::vector<int> containers,
                               std::vector<int> items, size_t cargo_size) {
      using namespace std;
      vector<int> pile;
      auto count = min(size(containers), size(items));
      for (size_t i = 0; i < count; ++i) {
        for (int container = 0; container < containers[i]; ++container) {
          pile.push_back(items[i]);
          push_heap(begin(pile), end(pile));
        }
      }
      size_t amount = 0;
      for (size_t i = 0; i < cargo_size; ++i) {
        pop_heap(begin(pile), end(pile));
        amount += pile.back();
        pile.pop_back();
      }
      return amount;
    }
  }  // namespace mzn
}  // namespace coin
