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

TEST(test_affine_transformation, test_rotation_1) {
  s21::Parser parser;
  s21::S21Matrix point_matrix(4, 1);
  double result[9] = {2.477, 1.966, 3.0, 3.075, 3.247, 4.0, 3.672, 4.529, 5.0};
  double angle = 20;
  double point[3] = {3, 1, 3};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix[j][0] = point[j] + i;
    }
    point_matrix[3][0] = 1;
    parser.matrix_points.push_back(point_matrix);
  }
  s21::AffineTransformation tramform;
  tramform.rotation_points(&parser, s21::AxisZ, angle);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[i * 3 + j] * 1000) -
                       round(point_matrix[j][0] * 1000)) < 1);
    }
  }
}

TEST(test_affine_transformation, test_rotation_2) {
  s21::Parser parser;
  s21::S21Matrix point_matrix(4, 1);
  double result[9] = {-4.048, 2.0,    -4.197, -5.247, 3.0,
                      -4.946, -6.447, 4.0,    -5.696};
  double angle = -193;
  double point[3] = {3, 1, 3};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix[j][0] = point[j] + (i + j);
    }
    point_matrix[3][0] = 1;
    parser.matrix_points.push_back(point_matrix);
  }
  s21::AffineTransformation tramform;
  tramform.rotation_points(&parser, s21::AxisY, angle);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[i * 3 + j] * 1000) -
                       round(point_matrix[j][0] * 1000)) < 1);
    }
  }
}

TEST(test_affine_transformation, test_rotation_3) {
  s21::Parser parser;
  s21::S21Matrix point_matrix(4, 1);
  double result[9] = {3.0,   -5.171, -1.502, 4.0,   -6.575,
                      -1.33, 5.0,    -7.979, -1.158};
  double angle = -2648;
  double point[3] = {3, 1, 3};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix[j][0] = point[j] + (i + j);
    }
    point_matrix[3][0] = 1;
    parser.matrix_points.push_back(point_matrix);
  }
  s21::AffineTransformation tramform;
  tramform.rotation_points(&parser, s21::AxisX, angle);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[i * 3 + j] * 1000) -
                       round(point_matrix[j][0] * 1000)) < 1);
    }
  }
}

TEST(test_affine_transformation, test_scale_1) {
  s21::Parser parser;
  double x = 1.2;
  double y = 3.2;
  double z = 0.25;
  s21::S21Matrix point_matrix(4, 1);
  s21::S21Matrix result(3, 3);
  double point[3] = {3, 1, 3};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix[j][0] = point[j] + (i + j);
    }
    result[0][i] = point_matrix[0][0] * x;
    result[1][i] = point_matrix[1][0] * y;
    result[2][i] = point_matrix[2][0] * z;
    point_matrix[3][0] = 1;
    parser.matrix_points.push_back(point_matrix);
  }
  s21::AffineTransformation tramform;
  tramform.scale_points(&parser, x, y, z);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[j][i] * 1000) -
                       round(point_matrix[j][0] * 1000)) < 1);
    }
  }
}