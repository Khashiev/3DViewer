#include <gtest/gtest.h>

#include "../model/s21_affine_transformation.h"
#include "../model/s21_affine_transformation_facade.h"
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
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.move(&parser, 1, -1, 4);
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
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.rotate(&parser, s21::AxisZ, angle);
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
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.rotate(&parser, s21::AxisY, angle);
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
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.rotate(&parser, s21::AxisX, angle);
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
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.scale(&parser, x, y, z);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      point_matrix = parser.matrix_points[i];
      ASSERT_TRUE(fabs(round(result[j][i] * 1000) -
                       round(point_matrix[j][0] * 1000)) < 1);
    }
  }
}

TEST(test_affine_transformation, test_go_to_center) {
  s21::Parser parser;
  s21::S21Matrix point1(4, 1);
  s21::AffineTransformation& aff = s21::AffineTransformation::getInstance();
  double delta = aff.get_delta_view() / 2;
  point1[0][0] = -3;
  point1[1][0] = 2;
  point1[3][0] = 1;
  parser.matrix_points.push_back(point1);
  point1[0][0] = -3;
  point1[1][0] = 5;
  point1[3][0] = 1;
  parser.matrix_points.push_back(point1);
  point1[0][0] = -6;
  point1[1][0] = 5;
  point1[3][0] = 1;
  parser.matrix_points.push_back(point1);
  point1[0][0] = -6;
  point1[1][0] = 2;
  point1[3][0] = 1;
  parser.matrix_points.push_back(point1);
  parser.min_max.x_max = -3;
  parser.min_max.x_min = -6;
  parser.min_max.y_max = 5;
  parser.min_max.y_min = 2;
  parser.min_max.z_max = 0;
  parser.min_max.z_min = 0;
  double res_center_x[4] = {1 * delta, 1 * delta, -1 * delta, -1 * delta};
  double res_center_y[4] = {-1 * delta, 1 * delta, 1 * delta, -1 * delta};
  s21::AffineTransformationFacade& tramform =
      s21::AffineTransformationFacade::getInstance();
  tramform.normalize(&parser);
  for (int i = 0; i < 4; i++) {
    ASSERT_TRUE(fabs(round(res_center_x[i] * 1000) -
                     round(parser.matrix_points[i][0][0] * 1000)) < 1);
    ASSERT_TRUE(fabs(round(res_center_y[i] * 1000) -
                     round(parser.matrix_points[i][1][0] * 1000)) < 1);
    ASSERT_TRUE(fabs(round(0 * 1000) -
                     round(parser.matrix_points[i][2][0] * 1000)) < 1);
  }
  ASSERT_TRUE(
      fabs(round(1 * 1000 * delta) - round(parser.min_max.x_max * 1000)) < 1);
  ASSERT_TRUE(
      fabs(round(-1 * 1000 * delta) - round(parser.min_max.x_min * 1000)) < 1);
  ASSERT_TRUE(
      fabs(round(1 * 1000 * delta) - round(parser.min_max.y_max * 1000)) < 1);
  ASSERT_TRUE(
      fabs(round(-1 * 1000 * delta) - round(parser.min_max.y_min * 1000)) < 1);
  ASSERT_TRUE(
      fabs(round(0 * 1000 * delta) - round(parser.min_max.z_max * 1000)) < 1);
  ASSERT_TRUE(
      fabs(round(0 * 1000 * delta) - round(parser.min_max.z_min * 1000)) < 1);
}

TEST(test_affine_transformation, test_multi_1) {
  s21::Parser parser;
  s21::AffineTransformationFacade& aff =
      s21::AffineTransformationFacade::getInstance();
  s21::S21Matrix point1(4, 1);
  double x_arr[4] = {-3, -3, -6, -6};
  double y_arr[4] = {13, 5, 7, 13};
  double z_arr[4] = {13, 3, 1, -31};
  for (int i = 0; i < 4; i++) {
    point1[0][0] = x_arr[i];
    point1[1][0] = y_arr[i];
    point1[2][0] = z_arr[i];
    point1[3][0] = 1;
    parser.matrix_points.push_back(point1);
  }
  aff.move(&parser, 13, -11, 13);
  aff.move(&parser, -13, 11, -13);
  aff.scale(&parser, 0.25, 0.25, 0.25);
  aff.scale(&parser, 4, 4, 4);
  aff.move(&parser, -33, -111, 13.33);
  aff.move(&parser, 33, 111, -13.33);
  aff.scale(&parser, 0.1, 0.1, 0.1);
  aff.scale(&parser, 10, 10, 10);
  aff.rotate(&parser, s21::AxisX, 15);
  aff.rotate(&parser, s21::AxisX, -15);
  aff.rotate(&parser, s21::AxisY, -115);
  aff.rotate(&parser, s21::AxisY, 115);
  aff.rotate(&parser, s21::AxisZ, 1.315);
  aff.rotate(&parser, s21::AxisZ, -1.315);
  for (int i = 0; i < 4; i++) {
    ASSERT_TRUE(fabs(round(x_arr[i] * 1000) -
                     round(parser.matrix_points[i][0][0] * 1000)) < 1);
    ASSERT_TRUE(fabs(round(y_arr[i] * 1000) -
                     round(parser.matrix_points[i][1][0] * 1000)) < 1);
    ASSERT_TRUE(fabs(round(z_arr[i] * 1000) -
                     round(parser.matrix_points[i][2][0] * 1000)) < 1);
  }
}
