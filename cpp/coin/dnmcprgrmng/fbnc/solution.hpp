#pragma once

#include <unordered_map>
#include <vector>

namespace coin {
  namespace dnmcprgrmng {
    namespace mztn {
      using fibo_memo = std::unordered_map<size_t, unsigned long>;

      unsigned long fibo(size_t n, fibo_memo& memo) {
        if (n == 1 or n == 2) return 1;
        if (memo.find(n) != memo.end()) return memo[n];
        memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
        return memo[n];
      }

      unsigned long fibo(size_t n) {
        fibo_memo memo{};
        return fibo(n, memo);
      }
    }  // namespace mztn

    namespace tbltn {
      unsigned long fibo(size_t n) {
        using namespace std;
        std::vector<unsigned long> table(n + 3, 0);
        table[1] = 1;
        for (size_t index = 0; index <= n; ++index) {
          auto const& value = table[index];
          table[index + 1] += value;
          table[index + 2] += value;
        }
        return table[n];
      }
    }  // namespace tbltn
  }    // namespace dnmcprgrmng
}  // namespace coin
