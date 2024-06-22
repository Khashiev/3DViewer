#include <gtest/gtest.h>

#include "../model/s21_affine_transformation.h"
#include "../model/s21_matrix_oop.h"
#include "../model/s21_parser.h"

TEST(test_affine_transformation, test_move_1) {
  s21::Parser parser;
  s21::S21Matrix point_matrix(4, 1);
  double point[3] = {3, 1, 3};
  double move[3] = {1, -1, 4};
  double result[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix[j][0] = point[j] + i;
      result[i][j] = point[j] + i + move[j];
    }
    point_matrix[3][0] = 1;
    parser.matrix_points.push_back(point_matrix);
  }
  s21::AffineTransformation tramform;
  tramform.move_points(&parser, 1, -1, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[i][j] * 1000000) -
                       round(point_matrix[j][0] * 1000000)) < 1);
    }
  }
}
