#include <gmock/gmock.h>

#include <iostream>

#include "solution.hpp"

using namespace ::coin::prstrg;
using namespace ::std;
using namespace ::testing;

TEST(cntsqrs, distance_correctness) {
  EXPECT_THAT(distance(point_t{0, 0}, point_t{0, 1}), Eq(1));
  EXPECT_THAT(distance(point_t{1, 0}, point_t{0, 0}), Eq(1));
  EXPECT_NEAR(distance(point_t{0, 0}, point_t{1, 1}), 1.41, 0.01);
}

TEST(cntsqrs, is_square_correctness) {
  EXPECT_THAT(is_square(point_vec_t{{0, 0}, {0, 2}, {2, 0}, {2, 2}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{0, 1}, {2, 1}, {1, 0}, {1, 2}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{1, 0}, {0, 2}, {2, 3}, {3, 1}}), Eq(true));
  EXPECT_THAT(is_square(point_vec_t{{1, 0}, {3, 4}, {0, 3}, {4, 1}}), Eq(true));
}

ostream& operator<<(ostream& stream, point_t const& point) {
  stream << point.x << "," << point.y;
  return stream;
}

ostream& operator<<(ostream& stream, segment_t const& segment) {
  stream << segment.first << "-" << segment.second;
  return stream;
}

bool operator==(segment_t const& first, segment_t const& second) {
  return first.first == second.first and first.second == second.second;
}

MATCHER_P(PointEq, other, "point_t") {
  return arg.x == other.x and arg.y == other.y;
}

MATCHER_P(SegmentEq, other, "segment_t") {
  return (arg.first == other.first and arg.second == other.second) or
         (arg.first == other.second and arg.second == other.first);
}

TEST(cntsqrs, orthogonal_correctness) {
  EXPECT_THAT(segment_t({{0, 0}, {2, 2}}).orthogonal(),
              SegmentEq(segment_t{{0, 2}, {2, 0}}));
  EXPECT_THAT(segment_t({{1, 0}, {1, 2}}).orthogonal(),
              SegmentEq(segment_t{{2, 1}, {0, 1}}));
  EXPECT_THAT(segment_t({{0, 2}, {3, 1}}).orthogonal(),
              SegmentEq(segment_t{{1, 0}, {2, 3}}));
}

TEST(cntsqrs, count_squares_correctness) {
  EXPECT_THAT(count_squares({{0, 0}, {0, 2}, {2, 0}, {2, 2}}), Eq(1));
  EXPECT_THAT(
      count_squares({{0, 0}, {0, 2}, {2, 0}, {2, 2}, {0, 4}, {4, 0}, {4, 4}}),
      Eq(2));
  EXPECT_THAT(count_squares({{0, 0}, {0, 1}, {1, 0}, {1, 1}}), Eq(1));
  EXPECT_THAT(
      count_squares({{0, 0}, {0, 2}, {2, 0}, {2, 2}, {0, 3}, {3, 0}, {3, 3}}),
      Eq(2));
}
