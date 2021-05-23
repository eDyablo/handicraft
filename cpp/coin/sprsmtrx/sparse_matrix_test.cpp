#include "sparse_matrix.hpp"

#include <gmock/gmock.h>
#include <vector>

using namespace ::testing;
using namespace ::std;

using matrix2d_t = ::coin::sprsmtrx::matrix2d_t<int>;

TEST(matrix2d, has_no_elements_by_default) {
  matrix2d_t matrix(2, 3);
  EXPECT_THAT(matrix.size(), Eq(0));
}

TEST(matrix2d, has_one_element_when_set_one_element_to_one) {
  matrix2d_t matrix(2, 2);
  matrix.set(0, 0, 1);
  EXPECT_THAT(matrix.size(), Eq(1));
}

TEST(matrix2d, has_zero_elements_when_set_one_element_to_zero) {
  matrix2d_t matrix(2, 2);
  matrix.set(0, 0, 0);
  EXPECT_THAT(matrix.size(), Eq(0));
}

TEST(matrix2d, has_two_elements_when_set_two_distinct_elements_to_one) {
  matrix2d_t matrix(2, 2);
  matrix.set(0, 0, 1);
  matrix.set(1, 1, 1);
  EXPECT_THAT(matrix.size(), Eq(2));
}

TEST(matrix2d, can_retrieve_elements_set_before) {
  matrix2d_t matrix(2, 2);
  matrix.set(0, 0, 1);
  matrix.set(1, 1, 2);
  EXPECT_THAT(matrix.at(0, 0), Eq(1));
}

TEST(matrix2d, get_zero_when_retrive_element_not_set_before) {
  matrix2d_t matrix(2, 2);
  EXPECT_THAT(matrix.at(0, 0), Eq(0));
  EXPECT_THAT(matrix.at(0, 1), Eq(0));
  EXPECT_THAT(matrix.at(1, 0), Eq(0));
  EXPECT_THAT(matrix.at(1, 1), Eq(0));
}

TEST(matrix2d, multiply_one_row_matrix_by_vector) {
  matrix2d_t matrix(1, 2);
  matrix.set(0, 0, 1);
  matrix.set(0, 1, 2);
  auto const result = matrix * vector<matrix2d_t::element_t>{3, 4};
  EXPECT_THAT(result, ElementsAreArray({11}));
}

TEST(matrix2d, multiply_two_rows_matrix_by_vector) {
  matrix2d_t matrix(2, 2);
  matrix.set(0, 0, 1);
  matrix.set(0, 1, 2);
  matrix.set(1, 0, 3);
  matrix.set(1, 1, 4);
  auto const result = matrix * vector<matrix2d_t::element_t>{3, 4};
  EXPECT_THAT(result, ElementsAreArray({11, 25}));
}
