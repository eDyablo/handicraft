#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    namespace mztn {
      using grid_travel_memo = std::unordered_map<size_t, unsigned long>;

      size_t grid_travel_ways(size_t width, size_t height,
                              grid_travel_memo& memo) {
        auto const key = width * 1000 + height;
        if (memo.find(key) != memo.end()) return memo[key];
        if (width == 0 or height == 0) return 0;
        if (width == 1 or height == 1) return 1;
        memo[key] = grid_travel_ways(width - 1, height, memo) +
                    grid_travel_ways(width, height - 1, memo);
        return memo[key];
      }

      size_t grid_travel_ways(size_t width, size_t height) {
        grid_travel_memo memo;
        return grid_travel_ways(width, height, memo);
      }
    }  // namespace mztn

    namespace tbltn {
      /**
       * Tabulated solution:
       * time:  O(w*s)
       * space: O(w*s)
       **/
      size_t grid_travel_ways(size_t width, size_t height) {
        size_t table[width + 1][height + 1];
        std::fill_n(&table[0][0], (width + 1) * (height + 1), 0);
        table[1][1] = 1;
        for (auto w = 0; w <= width; ++w) {
          for (auto h = 0; h <= height; ++h) {
            auto const& value = table[w][h];
            if (w < width) table[w + 1][h] += value;
            if (h < height) table[w][h + 1] += value;
          }
        }
        return table[width][height];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
