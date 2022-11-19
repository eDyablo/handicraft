#pragma once

#include <vector>

namespace epc {
  template <typename T, typename Op>
  class binary_counter_t {
    T zero;
    Op operation;
    std::vector<T> counter;

   public:
    binary_counter_t(const T& zero, Op operation = Op())
        : zero(zero), operation(operation) {}

    binary_counter_t& add(T carry) {
      carry = add(counter.begin(), counter.end(), carry);
      if (carry != zero) {
        counter.push_back(carry);
      }
      return *this;
    }

    T reduce() const { return reduce(counter.begin(), counter.end()); }

    size_t size() const { return counter.size(); }

   private:
    template <typename I>
    T add(I first, I last, T carry) {
      if (carry == zero) {
        return zero;
      }
      for (; first != last; ++first) {
        if (*first == zero) {
          *first = carry;
          return zero;
        } else {
          carry = operation(*first, carry);
          *first = zero;
        }
      }
      return carry;
    }

    template <typename I>
    T reduce(I first, I last) const {
      while (first != last and *first == zero) {
        ++first;
      }
      if (first == last) {
        return zero;
      }
      T result = *first;
      for (++first; first != last; ++first) {
        if (*first != zero) {
          result = operation(*first, result);
        }
      }
      return result;
    }
  };
}  // namespace epc
