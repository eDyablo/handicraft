#pragma once

#include <unordered_map>

namespace coin {
  namespace dnmcprgrmng {
    using fibo_memo = std::unordered_map<size_t, unsigned long>;

    unsigned long fibo(size_t n, fibo_memo& memo) {
      if (n == 1 or n == 2) {
        return 1;
      }
      if (memo.find(n) != memo.end()) {
        return memo[n];
      }
      memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
      return memo[n];
    }

    unsigned long fibo(size_t n) {
      fibo_memo memo{};
      return fibo(n, memo);
    }
  }  // namespace dnmcprgrmng
}  // namespace coin
