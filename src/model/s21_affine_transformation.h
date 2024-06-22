#ifndef CPP4_3DViewer_V_2_0_1_MODEL_S21_AFFINE_TRANSFORMATION_H
#define CPP4_3DViewer_V_2_0_1_MODEL_S21_AFFINE_TRANSFORMATION_H

#include <cmath>
#include <iostream>

#include "s21_matrix_oop.h"
#include "s21_parser.h"

namespace s21 {

typedef enum {
  AxisX = 0,
  AxisY = 1,
  AxisZ = 2,
} Axes;

class AffineTransformation {
 public:
  AffineTransformation();
  ~AffineTransformation();
  void move_points(Parser* parser, double move_x, double move_y, double move_z);
  void rotation_point(S21Matrix& point, Axes axis, double angle);
  void scale_point(S21Matrix& point, double* scale_ratio);

 private:
  S21Matrix create_transfer_matrix(double* moving_coordinates);
  S21Matrix create_rotation_X_matrix(double angle);
  S21Matrix create_rotation_Y_matrix(double angle);
  S21Matrix create_rotation_Z_matrix(double angle);
  S21Matrix create_scale_matrix(double* scale_ratio);
  void make_unit_matrix(S21Matrix& matrix);
  static constexpr int ORDER_TRANSFER_MATRIX = 4;
  static constexpr int DIMENSION_SPACE = 3;
  static constexpr double RAD_IN_DEGRE = 180.0;
};

void show_matrix(s21::S21Matrix& matrix);
}  // namespace s21

#endif