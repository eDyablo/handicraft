#include "span_chart.hpp"

#include <gmock/gmock.h>

using namespace std;

TEST(span_chart, newly_created_chart_is_valid) {
  auto chart = span_chart_t<size_t, char>('a');
  EXPECT_EQ('a', chart[chart.lowest_point]);
  EXPECT_EQ('a', chart[chart.highest_point / 2]);
  EXPECT_EQ('a', chart[chart.highest_point]);
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
}

TEST(span_chart, enroll_left_part_of_one_value_iterval) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(0, 1, 'b');
  EXPECT_EQ(size_t(2), chart.entries_count());
  EXPECT_EQ('b', chart[0]);
  EXPECT_EQ('a', chart[1]);
}

TEST(span_chart, enroll_middle_part_of_one_value_iterval) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(1000, 2000, 'b');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[999]);
  EXPECT_EQ('b', chart[1000]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, enroll_middle_part_of_two_values_span) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(1000, chart.highest_point, 'b');
  chart.enroll(500, 1500, 'c');
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[499]);
  EXPECT_EQ('c', chart[500]);
  EXPECT_EQ('c', chart[1499]);
  EXPECT_EQ('b', chart[1500]);
  EXPECT_EQ('b', chart[chart.highest_point - 1]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, enroll_maximum_possible_span) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(chart.lowest_point, chart.highest_point, 'b');
  EXPECT_EQ(size_t(2), chart.entries_count());
  EXPECT_EQ('b', chart[0]);
  EXPECT_EQ('b', chart[chart.highest_point / 2]);
  EXPECT_EQ('b', chart[chart.highest_point - 1]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, reenroll_value_for_part_of_span) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(100, 200, 'b');
  chart.enroll(100, 200, 'c');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[99]);
  EXPECT_EQ('c', chart[100]);
  EXPECT_EQ('c', chart[150]);
  EXPECT_EQ('c', chart[199]);
  EXPECT_EQ('a', chart[200]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, enroll_adjacent_spans) {
  auto chart = span_chart_t<size_t, char>('c');
  chart.enroll(0, 100, 't');
  chart.enroll(100, 200, 'h');
  chart.enroll(200, 300, 'i');
  chart.enroll(300, 400, 'n');
  chart.enroll(400, chart.highest_point, 'k');
  EXPECT_EQ(sizeof("think"), chart.entries_count());
  EXPECT_EQ('t', chart[0]);
  EXPECT_EQ('t', chart[99]);
  EXPECT_EQ('h', chart[100]);
  EXPECT_EQ('h', chart[199]);
  EXPECT_EQ('i', chart[200]);
  EXPECT_EQ('i', chart[299]);
  EXPECT_EQ('n', chart[300]);
  EXPECT_EQ('n', chart[399]);
  EXPECT_EQ('k', chart[400]);
  EXPECT_EQ('c', chart[chart.highest_point]);
}

TEST(span_chart, stress_by_adding_1000_adjacent_spans) {
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 1'000;
  for (size_t i = 0; i < count; ++i) {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_2000_adjacent_spans) {
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 2'000;
  for (size_t i = 0; i < count; ++i) {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_3000_adjacent_spans) {
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 3'000;
  for (size_t i = 0; i < count; ++i) {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

/*TEST(span_chart, stress_by_adding_4000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 4'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_5000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 5'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_6000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 6'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_7000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 7'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_8000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 8'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_9000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 9'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_10000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 10'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_20000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 20'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_30000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 30'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_40000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 40'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}

TEST(span_chart, stress_by_adding_50000_adjacent_spans)
{
  auto chart = span_chart_t<size_t, size_t>(0);
  size_t constexpr count = 50'000;
  for (size_t i = 0; i < count; ++i)
  {
    chart.enroll(i, chart.highest_point, i);
  }
  EXPECT_EQ(count + 1, chart.entries_count());
}*/

TEST(span_chart, do_not_change_when_span_is_empty) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(10, 10, ' ');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, do_not_change_when_span_is_reversed) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(10, 1, ' ');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[5]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, enroll_divergent_spans_at_the_middle) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(30, 31, 'b');
  chart.enroll(20, 41, 'c');
  chart.enroll(10, 51, 'd');
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('d', chart[20]);
  EXPECT_EQ('d', chart[30]);
  EXPECT_EQ(size_t(3), chart.entries_count());
}

TEST(span_chart, enroll_convergent_spans_at_the_middle) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(10, 51, 'b');
  chart.enroll(20, 41, 'c');
  chart.enroll(30, 31, 'd');
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('b', chart[10]);
  EXPECT_EQ('c', chart[20]);
  EXPECT_EQ('d', chart[30]);
  EXPECT_EQ(size_t(7), chart.entries_count());
}

TEST(span_chart, enroll_two_distant_span_of_the_same_value) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(10, 21, 'b');
  chart.enroll(30, 41, 'b');
  EXPECT_EQ('a', chart[5]);
  EXPECT_EQ('b', chart[15]);
  EXPECT_EQ('a', chart[25]);
  EXPECT_EQ('b', chart[35]);
  EXPECT_EQ('a', chart[45]);
  EXPECT_EQ(size_t(5), chart.entries_count());
}

TEST(span_chart, enroll_of_initial_value_to_whole_range_has_no_effect) {
  auto chart = span_chart_t<size_t, char>('a');
  chart.enroll(0, chart.highest_point, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[chart.highest_point]);
}

TEST(span_chart, enroll_of_initial_value_to_left_edge_has_no_effect) {
  auto chart = span_chart_t<size_t, char>('a');
  auto const leftEdge = chart.lowest_point;
  chart.enroll(leftEdge, leftEdge + 1, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[leftEdge]);
}

TEST(span_chart, enroll_of_initial_value_to_right_edge_has_no_effect) {
  auto chart = span_chart_t<size_t, char>('a');
  auto const rightEdge = chart.highest_point;
  chart.enroll(rightEdge - 1, rightEdge, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[rightEdge]);
}

TEST(span_chart, enroll_of_initial_value_to_the_middle_has_no_effect) {
  auto chart = span_chart_t<size_t, char>('a');
  auto const leftEdge = chart.lowest_point;
  auto const rightEdge = chart.highest_point;
  auto constexpr gap = 10;
  chart.enroll(leftEdge + gap, rightEdge - gap, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_EQ('a', chart[rightEdge]);
  EXPECT_EQ('a', chart[leftEdge]);
}

TEST(span_chart, enroll_and_revert_to_initial) {
  using key_t = size_t;
  auto chart = span_chart_t<key_t, char>('a');
  auto constexpr min = numeric_limits<key_t>::min();
  auto constexpr max = numeric_limits<key_t>::max();

  chart.enroll(max / 2, max, 'b');
  chart.enroll(0, max, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
}

TEST(span_chart, complex) {
  using key_t = size_t;
  auto chart = span_chart_t<key_t, char>('a');
  auto constexpr min = numeric_limits<key_t>::min();
  auto constexpr max = numeric_limits<key_t>::max();

  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100, max, 'b');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[99]);
  EXPECT_EQ('b', chart[100]);

  chart.enroll(50, 150, 'c');

  EXPECT_EQ(size_t(4), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[49]);
  EXPECT_EQ('c', chart[50]);
  EXPECT_EQ('c', chart[149]);
  EXPECT_EQ('b', chart[150]);

  chart.enroll(100, 150, 'd');
  EXPECT_EQ(size_t(5), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[49]);
  EXPECT_EQ('c', chart[50]);
  EXPECT_EQ('c', chart[99]);
  EXPECT_EQ('d', chart[100]);
  EXPECT_EQ('d', chart[149]);
  EXPECT_EQ('b', chart[150]);

  chart.enroll(100, 150, 'e');
  EXPECT_EQ(size_t(5), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[49]);
  EXPECT_EQ('c', chart[50]);
  EXPECT_EQ('c', chart[99]);
  EXPECT_EQ('e', chart[100]);
  EXPECT_EQ('e', chart[149]);
  EXPECT_EQ('b', chart[150]);

  chart.enroll(80, 170, 'f');
  EXPECT_EQ(size_t(5), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[49]);
  EXPECT_EQ('c', chart[50]);
  EXPECT_EQ('c', chart[79]);
  EXPECT_EQ('f', chart[80]);
  EXPECT_EQ('f', chart[169]);
  EXPECT_EQ('b', chart[170]);

  chart.enroll(100, 150, 'd');
  EXPECT_EQ(size_t(7), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[49]);
  EXPECT_EQ('c', chart[50]);
  EXPECT_EQ('c', chart[79]);
  EXPECT_EQ('f', chart[80]);
  EXPECT_EQ('f', chart[99]);
  EXPECT_EQ('d', chart[100]);
  EXPECT_EQ('d', chart[149]);
  EXPECT_EQ('f', chart[150]);
  EXPECT_EQ('f', chart[169]);
  EXPECT_EQ('b', chart[170]);

  chart.enroll(1, max, 'b');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(1, max, 'c');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(1, max, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100, 200, 'b');
  chart.enroll(300, 400, 'c');
  chart.enroll(500, 600, 'd');
  EXPECT_EQ(size_t(7), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100 - 1, 200 + 1, 'b');
  chart.enroll(300 - 1, 400 + 1, 'c');
  chart.enroll(500 - 1, 600 + 1, 'd');
  EXPECT_EQ(size_t(7), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100 + 1, 200 - 1, 'b');
  chart.enroll(300 + 1, 400 - 1, 'c');
  chart.enroll(500 + 1, 600 - 1, 'd');
  EXPECT_EQ(size_t(7), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(150, 151, 'c');
  chart.enroll(350, 351, 'd');
  chart.enroll(550, 551, 'b');
  EXPECT_EQ(size_t(13), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(1, max, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100, 200, 'b');
  chart.enroll(300, 400, 'c');
  chart.enroll(500, 600, 'd');
  chart.enroll(100, 200, 'a');
  chart.enroll(300, 400, 'a');
  chart.enroll(500, 600, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(100, 200, 'b');
  chart.enroll(300, 400, 'c');
  chart.enroll(500, 600, 'd');
  chart.enroll(100 - 1, 200 + 1, 'a');
  chart.enroll(300 - 1, 400 + 1, 'a');
  chart.enroll(500 - 1, 600 + 1, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  /*chart.enroll(100, 200, 'b');
  chart.enroll(300, 400, 'c');
  chart.enroll(500, 600, 'd');
  chart.enroll(0, 150, 'a');
  //EXPECT_TRUE(chart.is_dense());
  EXPECT_EQ(size_t(7), chart.entries_count());*/
}

TEST(span_chart, shorten_middle_span) {
  using key_t = size_t;
  auto chart = span_chart_t<key_t, char>('a');
  auto constexpr min = numeric_limits<key_t>::min();
  auto constexpr max = numeric_limits<key_t>::max();

  chart.enroll(0, max, 'a');
  chart.enroll(100, 200, 'b');
  chart.enroll(100, 100 + 1, 'a');
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());

  chart.enroll(0, max, 'a');
  chart.enroll(100, 200, 'b');
  chart.enroll(199, 200, 'a');
  EXPECT_EQ('a', chart[0]);
  EXPECT_EQ('a', chart[200]);
  EXPECT_EQ(size_t(3), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
}

TEST(span_chart, remove_spans) {
  using key_t = size_t;
  auto chart = span_chart_t<key_t, char>('a');

  chart.enroll(100, 200, 'b');
  chart.enroll(300, 400, 'c');
  chart.enroll(300, 400, 'a');
  chart.enroll(100, 200, 'a');
  EXPECT_EQ(size_t(1), chart.entries_count());
  EXPECT_TRUE(chart.is_dense());
}
