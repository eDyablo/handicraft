#include "binary_counter.hpp"

#include <gmock/gmock.h>

#include <functional>
#include <string>

namespace epc {
  namespace {
    using ::testing::Eq;

    TEST(BinaryCounter, ReduceToZeroWhenNothingAdded) {
      char zero = '0';
      binary_counter_t<char, std::plus<char>> counter(zero);
      EXPECT_THAT(counter.reduce(), Eq(zero));
    }

    TEST(BinaryCounter, ReduceAdded) {
      binary_counter_t<int, std::plus<int>> counter(0);
      counter.add(1);
      // [1]
      EXPECT_THAT(counter.size(), Eq(1));
      EXPECT_THAT(counter.reduce(), Eq(1));

      counter.add(1);
      // [0, 2]
      EXPECT_THAT(counter.size(), Eq(2));
      EXPECT_THAT(counter.reduce(), Eq(2));

      counter.add(1);
      // [1, 2]
      EXPECT_THAT(counter.size(), Eq(2));
      EXPECT_THAT(counter.reduce(), Eq(3));

      counter.add(1);
      // [0, 0, 4]
      EXPECT_THAT(counter.size(), Eq(3));
      EXPECT_THAT(counter.reduce(), Eq(4));

      counter.add(1);
      // [1, 0, 4]
      EXPECT_THAT(counter.size(), Eq(3));
      EXPECT_THAT(counter.reduce(), Eq(5));

      counter.add(1);
      // [0, 2, 4]
      EXPECT_THAT(counter.size(), Eq(3));
      EXPECT_THAT(counter.reduce(), Eq(6));

      counter.add(1);
      // [1, 2, 4]
      EXPECT_THAT(counter.size(), Eq(3));
      EXPECT_THAT(counter.reduce(), Eq(7));

      counter.add(1);
      // [0, 0, 0, 8]
      EXPECT_THAT(counter.size(), Eq(4));
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
  }  // namespace
}  // namespace epc
