#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

namespace coin {
  namespace mzn {
    template <typename Label>
    auto split_up_scenes(std::vector<Label> const& shots) {
      using namespace std;
      using interval_t = pair<size_t, size_t>;
      using label_t = Label;
      using lookup_t = unordered_map<label_t, interval_t>;
      lookup_t lookup;
      size_t position = 0;
      for (auto label : shots) {
        if (lookup.find(label) == end(lookup)) {
          lookup[label] = make_pair(position, position);
        } else {
          lookup[label].second = position;
        }
        ++position;
      }
      vector<int> marks(size(shots), 0);
      for (auto const& record : lookup) {
        auto const& interval = record.second;
        ++marks[interval.first];
        --marks[interval.second];
      }
      vector<size_t> scenes;
      size_t scene_length = 0;
      partial_sum(begin(marks), end(marks), begin(marks));
      for (auto mark : marks) {
        ++scene_length;
        if (mark == 0) {
          scenes.push_back(scene_length);
          scene_length = 0;
        }
      }
      return scenes;
    }
  }  // namespace mzn
}  // namespace coin
