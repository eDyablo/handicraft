#include <string>
#include <unordered_map>

namespace coin {
  namespace dnmcprgrmng {
    using grid_travel_memo = std::unordered_map<size_t, unsigned long>;

    size_t grid_travel_ways(size_t width, size_t height,
                            grid_travel_memo& memo) {
      auto const key = width * 1000 + height;
      if (memo.find(key) != memo.end()) {
        return memo[key];
      }
      if (width == 0 or height == 0) {
        return 0;
      }
      if (width == 1 or height == 1) {
        return 1;
      }
      memo[key] = grid_travel_ways(width - 1, height, memo) +
                  grid_travel_ways(width, height - 1, memo);
      return memo[key];
    }

    size_t grid_travel_ways(size_t width, size_t height) {
      grid_travel_memo memo;
      return grid_travel_ways(width, height, memo);
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
