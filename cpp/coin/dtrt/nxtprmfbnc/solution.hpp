#pragma once

#include <cmath>

namespace coin {
  namespace dtrt {
    bool is_prime(long number) {
      using namespace std;
      const long bound = floor(sqrt(number));
      for (long i = 2; i <= bound; ++i) {
        if (number % i == 0) return false;
      }
      return true;
    }

    long fibonacci(size_t number) {
      long current = 1;
      long next = 1;
      for (size_t i = 1; i < number; ++i) {
        auto const sum = current + next;
        current = next;
        next = sum;
      }
      return next;
    }

    long next_prime_fibonacci(size_t number) {
      for (size_t i = 1;; ++i) {
        auto const fib = fibonacci(i);
        if (fib > number and is_prime(fib)) return fib;
      }
      return 0;
    }
  }  // namespace dtrt
}  // namespace coin
