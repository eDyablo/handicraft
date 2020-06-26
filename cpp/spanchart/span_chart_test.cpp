#include "span_chart.hpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(span_chart_test) {
  TEST_METHOD(newly_created_chart_is_valid)
  {
    auto chart = span_chart_t<size_t, char>('a');
    Assert::AreEqual('a', chart[chart.lowest_point]);
    Assert::AreEqual('a', chart[chart.highest_point / 2]);
    Assert::AreEqual('a', chart[chart.highest_point]);
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::IsTrue(chart.is_dense());
  }

  TEST_METHOD(enroll_left_part_of_one_value_iterval)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(0, 1, 'b');
    Assert::AreEqual(size_t(2), chart.entries_count());
    Assert::AreEqual('b', chart[0]);
    Assert::AreEqual('a', chart[1]);
  }


  TEST_METHOD(enroll_middle_part_of_one_value_iterval)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(1000, 2000, 'b');
    Assert::AreEqual(size_t(3), chart.entries_count());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[999]);
    Assert::AreEqual('b', chart[1000]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(enroll_middle_part_of_two_values_span)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(1000, chart.highest_point, 'b');
    chart.enroll(500, 1500, 'c');
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[499]);
    Assert::AreEqual('c', chart[500]);
    Assert::AreEqual('c', chart[1499]);
    Assert::AreEqual('b', chart[1500]);
    Assert::AreEqual('b', chart[chart.highest_point - 1]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(enroll_maximum_possible_span)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(chart.lowest_point, chart.highest_point, 'b');
    Assert::AreEqual(size_t(2), chart.entries_count());
    Assert::AreEqual('b', chart[0]);
    Assert::AreEqual('b', chart[chart.highest_point / 2]);
    Assert::AreEqual('b', chart[chart.highest_point - 1]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(reenroll_value_for_part_of_span)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(100, 200, 'b');
    chart.enroll(100, 200, 'c');
    Assert::AreEqual(size_t(3), chart.entries_count());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[99]);
    Assert::AreEqual('c', chart[100]);
    Assert::AreEqual('c', chart[150]);
    Assert::AreEqual('c', chart[199]);
    Assert::AreEqual('a', chart[200]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(enroll_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, char>('c');
    chart.enroll(  0, 100, 't');
    chart.enroll(100, 200, 'h');
    chart.enroll(200, 300, 'i');
    chart.enroll(300, 400, 'n');
    chart.enroll(400, chart.highest_point, 'k');
    Assert::AreEqual(sizeof("think"), chart.entries_count());
    Assert::AreEqual('t', chart[0]);
    Assert::AreEqual('t', chart[99]);
    Assert::AreEqual('h', chart[100]);
    Assert::AreEqual('h', chart[199]);
    Assert::AreEqual('i', chart[200]);
    Assert::AreEqual('i', chart[299]);
    Assert::AreEqual('n', chart[300]);
    Assert::AreEqual('n', chart[399]);
    Assert::AreEqual('k', chart[400]);
    Assert::AreEqual('c', chart[chart.highest_point]);
  }

  TEST_METHOD(stress_by_adding_1000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 1'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_2000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 2'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_3000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 3'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  /*TEST_METHOD(stress_by_adding_4000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 4'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_5000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 5'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_6000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 6'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_7000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 7'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_8000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 8'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_9000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 9'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_10000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 10'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_20000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 20'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_30000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 30'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_40000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 40'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }

  TEST_METHOD(stress_by_adding_50000_adjacent_spans)
  {
    auto chart = span_chart_t<size_t, size_t>(0);
    size_t constexpr count = 50'000;
    for (size_t i = 0; i < count; ++i)
    {
      chart.enroll(i, chart.highest_point, i);
    }
    Assert::AreEqual(count + 1, chart.entries_count());
  }*/

  TEST_METHOD(do_not_change_when_span_is_empty)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(10, 10, ' ');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(do_not_change_when_span_is_reversed)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(10, 1, ' ');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[5]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(enroll_divergent_spans_at_the_middle)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(30, 31, 'b');
    chart.enroll(20, 41, 'c');
    chart.enroll(10, 51, 'd');
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('d', chart[20]);
    Assert::AreEqual('d', chart[30]);
    Assert::AreEqual(size_t(3), chart.entries_count());
  }

  TEST_METHOD(enroll_convergent_spans_at_the_middle)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(10, 51, 'b');
    chart.enroll(20, 41, 'c');
    chart.enroll(30, 31, 'd');
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('b', chart[10]);
    Assert::AreEqual('c', chart[20]);
    Assert::AreEqual('d', chart[30]);
    Assert::AreEqual(size_t(7), chart.entries_count());
  }

  TEST_METHOD(enroll_two_distant_span_of_the_same_value)
  {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(10, 21, 'b');
    chart.enroll(30, 41, 'b');
    Assert::AreEqual('a', chart[5]);
    Assert::AreEqual('b', chart[15]);
    Assert::AreEqual('a', chart[25]);
    Assert::AreEqual('b', chart[35]);
    Assert::AreEqual('a', chart[45]);
    Assert::AreEqual(size_t(5), chart.entries_count());
  }

  TEST_METHOD(enroll_of_initial_value_to_whole_range_has_no_effect) {
    auto chart = span_chart_t<size_t, char>('a');
    chart.enroll(0, chart.highest_point, 'a');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[chart.highest_point]);
  }

  TEST_METHOD(enroll_of_initial_value_to_left_edge_has_no_effect) {
    auto chart = span_chart_t<size_t, char>('a');
    auto const leftEdge = chart.lowest_point;
    chart.enroll(leftEdge, leftEdge + 1, 'a');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[leftEdge]);
  }

  TEST_METHOD(enroll_of_initial_value_to_right_edge_has_no_effect) {
    auto chart = span_chart_t<size_t, char>('a');
    auto const rightEdge = chart.highest_point;
    chart.enroll(rightEdge - 1, rightEdge, 'a');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[rightEdge]);
  }

  TEST_METHOD(enroll_of_initial_value_to_the_middle_has_no_effect) {
    auto chart = span_chart_t<size_t, char>('a');
    auto const leftEdge = chart.lowest_point;
    auto const rightEdge = chart.highest_point;
    auto constexpr gap = 10;
    chart.enroll(leftEdge + gap, rightEdge - gap, 'a');
    Assert::AreEqual(size_t(1), chart.entries_count());
    Assert::AreEqual('a', chart[rightEdge]);
    Assert::AreEqual('a', chart[leftEdge]);
  }

  TEST_METHOD(enroll_and_revert_to_initial) {
    using key_t = size_t;
    auto chart = span_chart_t<key_t, char>('a');
    auto constexpr min = numeric_limits<key_t>::min();
    auto constexpr max = numeric_limits<key_t>::max();

    chart.enroll(max/2, max, 'b');
    chart.enroll(0, max, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
  }

  TEST_METHOD(complex) {
    using key_t = size_t;
    auto chart = span_chart_t<key_t, char>('a');
    auto constexpr min = numeric_limits<key_t>::min();
    auto constexpr max = numeric_limits<key_t>::max();

    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(100, max, 'b');
    Assert::AreEqual(3ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[99]);
    Assert::AreEqual('b', chart[100]);

    chart.enroll(50, 150, 'c');
    
    Assert::AreEqual(4ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[49]);
    Assert::AreEqual('c', chart[50]);
    Assert::AreEqual('c', chart[149]);
    Assert::AreEqual('b', chart[150]);

    chart.enroll(100, 150, 'd');
    Assert::AreEqual(5ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[49]);
    Assert::AreEqual('c', chart[50]);
    Assert::AreEqual('c', chart[99]);
    Assert::AreEqual('d', chart[100]);
    Assert::AreEqual('d', chart[149]);
    Assert::AreEqual('b', chart[150]);

    chart.enroll(100, 150, 'e');
    Assert::AreEqual(5ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[49]);
    Assert::AreEqual('c', chart[50]);
    Assert::AreEqual('c', chart[99]);
    Assert::AreEqual('e', chart[100]);
    Assert::AreEqual('e', chart[149]);
    Assert::AreEqual('b', chart[150]);

    chart.enroll(80, 170, 'f');
    Assert::AreEqual(5ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[49]);
    Assert::AreEqual('c', chart[50]);
    Assert::AreEqual('c', chart[79]);
    Assert::AreEqual('f', chart[80]);
    Assert::AreEqual('f', chart[169]);
    Assert::AreEqual('b', chart[170]);

    chart.enroll(100, 150, 'd');
    Assert::AreEqual(7ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[49]);
    Assert::AreEqual('c', chart[50]);
    Assert::AreEqual('c', chart[79]);
    Assert::AreEqual('f', chart[80]);
    Assert::AreEqual('f', chart[99]);
    Assert::AreEqual('d', chart[100]);
    Assert::AreEqual('d', chart[149]);
    Assert::AreEqual('f', chart[150]);
    Assert::AreEqual('f', chart[169]);
    Assert::AreEqual('b', chart[170]);

    chart.enroll(1, max, 'b');
    Assert::AreEqual(3ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(1, max, 'c');
    Assert::AreEqual(3ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(1, max, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(100, 200, 'b');
    chart.enroll(300, 400, 'c');
    chart.enroll(500, 600, 'd');
    Assert::AreEqual(7ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());


    chart.enroll(100 - 1, 200 + 1, 'b');
    chart.enroll(300 - 1, 400 + 1, 'c');
    chart.enroll(500 - 1, 600 + 1, 'd');
    Assert::AreEqual(7ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());


    chart.enroll(100 + 1, 200 - 1, 'b');
    chart.enroll(300 + 1, 400 - 1, 'c');
    chart.enroll(500 + 1, 600 - 1, 'd');
    Assert::AreEqual(7ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());


    chart.enroll(150, 151, 'c');
    chart.enroll(350, 351, 'd');
    chart.enroll(550, 551, 'b');
    Assert::AreEqual(13ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(1, max, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(100, 200, 'b');
    chart.enroll(300, 400, 'c');
    chart.enroll(500, 600, 'd');
    chart.enroll(100, 200, 'a');
    chart.enroll(300, 400, 'a');
    chart.enroll(500, 600, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(100, 200, 'b');
    chart.enroll(300, 400, 'c');
    chart.enroll(500, 600, 'd');
    chart.enroll(100 - 1, 200 + 1, 'a');
    chart.enroll(300 - 1, 400 + 1, 'a');
    chart.enroll(500 - 1, 600 + 1, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    /*chart.enroll(100, 200, 'b');
    chart.enroll(300, 400, 'c');
    chart.enroll(500, 600, 'd');
    chart.enroll(0, 150, 'a');
    //Assert::IsTrue(chart.is_dense());
    Assert::AreEqual(7ui64, chart.entries_count());*/
  }

  TEST_METHOD(shorten_middle_span) {
    using key_t = size_t;
    auto chart = span_chart_t<key_t, char>('a');
    auto constexpr min = numeric_limits<key_t>::min();
    auto constexpr max = numeric_limits<key_t>::max();

    chart.enroll(0, max, 'a');
    chart.enroll(100, 200, 'b');
    chart.enroll(100, 100 + 1, 'a');
    Assert::AreEqual(3ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());

    chart.enroll(0, max, 'a');
    chart.enroll(100, 200, 'b');
    chart.enroll(199, 200, 'a');
    Assert::AreEqual('a', chart[0]);
    Assert::AreEqual('a', chart[200]);
    Assert::AreEqual(3ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
  }

  TEST_METHOD(remove_spans) {
    using key_t = size_t;
    auto chart = span_chart_t<key_t, char>('a');

    chart.enroll(100, 200, 'b');
    chart.enroll(300, 400, 'c');
    chart.enroll(300, 400, 'a');
    chart.enroll(100, 200, 'a');
    Assert::AreEqual(1ui64, chart.entries_count());
    Assert::IsTrue(chart.is_dense());
  }
};
