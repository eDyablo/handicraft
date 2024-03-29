#include "binary_counter.hpp"

#include <gmock/gmock.h>

#include <functional>
#include <limits>
#include <string>

namespace epc {
  namespace {
    using ::testing::Eq;
    using ::testing::SizeIs;

    TEST(BinaryCounter, ReduceToZeroWhenNothingAdded) {
      char zero = '0';
      binary_counter_t<char, std::plus<char>> counter(zero);
      EXPECT_THAT(counter.reduce(), Eq(zero));
    }

    TEST(BinaryCounter, ReduceAdded) {
      binary_counter_t<int, std::plus<int>> counter(0);
      EXPECT_THAT(counter, SizeIs(0));

      counter.add(1);
      // [1]
      EXPECT_THAT(counter, SizeIs(1));
      EXPECT_THAT(counter.reduce(), Eq(1));

      counter.add(1);
      // [0, 2]
      EXPECT_THAT(counter, SizeIs(2));
      EXPECT_THAT(counter.reduce(), Eq(2));

      counter.add(1);
      // [1, 2]
      EXPECT_THAT(counter, SizeIs(2));
      EXPECT_THAT(counter.reduce(), Eq(3));

      counter.add(1);
      // [0, 0, 4]
      EXPECT_THAT(counter, SizeIs(3));
      EXPECT_THAT(counter.reduce(), Eq(4));

      counter.add(1);
      // [1, 0, 4]
      EXPECT_THAT(counter, SizeIs(3));
      EXPECT_THAT(counter.reduce(), Eq(5));

      counter.add(1);
      // [0, 2, 4]
      EXPECT_THAT(counter, SizeIs(3));
      EXPECT_THAT(counter.reduce(), Eq(6));

      counter.add(1);
      // [1, 2, 4]
      EXPECT_THAT(counter, SizeIs(3));
      EXPECT_THAT(counter.reduce(), Eq(7));

      counter.add(1);
      // [0, 0, 0, 8]
      EXPECT_THAT(counter, SizeIs(4));
      EXPECT_THAT(counter.reduce(), Eq(8));
    }

    TEST(BinaryCounter, RetainsOrder) {
      binary_counter_t<std::string, std::plus<std::string>> counter(
          std::string{});
      std::string const symbols = "abcdefghijklmnopqrstuvwxyz";
      for (auto const symbol : symbols) {
        counter.add({symbol});
      }
      EXPECT_THAT(counter.reduce(), Eq(symbols));
    }

    TEST(BinaryCounter, SkipsZeros) {
      int const zero = 1;
      binary_counter_t<int, std::plus<int>> counter(zero);

      counter.add(zero);
      counter.add(zero);
      EXPECT_THAT(counter, SizeIs(0));
      EXPECT_THAT(counter.reduce(), Eq(zero));

      counter.add(2);
      counter.add(zero);
      counter.add(3);
      EXPECT_THAT(counter, SizeIs(2));
      EXPECT_THAT(counter.reduce(), Eq(5));
    }

    template <typename T>
    struct min {
      T operator()(T const& x, T const& y) const { return (y < x) ? y : x; }
    };

    TEST(BinaryCounter, FindMinimalElement) {
      binary_counter_t<int, min<int>> counter(std::numeric_limits<int>::max());
      for (const auto i : {5, 2, 4, 3, 1, 0}) {
        counter.add(i);
      }
      EXPECT_THAT(counter.reduce(), Eq(0));
    }
  }  // namespace
}  // namespace epc
