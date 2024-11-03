#include "s21_affine_transformation.h"

namespace s21 {

void AffineTransformation::move_points(Parser* parser, double move_x,
                                       double move_y, double move_z) {
  double moving_coordinates[3] = {move_x, move_y, move_z};
  S21Matrix transfer_matrix = create_transfer_matrix(moving_coordinates);
  S21Matrix point(3, 3);
  for (size_t i = 0; i < parser->matrix_points.size(); i++) {
    point = parser->matrix_points[i];
    parser->matrix_points[i] = transfer_matrix * point;
    parser->matrix_points[i][3][0] = 1;
  }
  parser->min_max.x_max -= move_x;
  parser->min_max.x_min -= move_x;
  parser->min_max.y_max -= move_y;
  parser->min_max.y_min -= move_y;
  parser->min_max.z_max -= move_z;
  parser->min_max.z_min -= move_z;
}

void AffineTransformation::rotation_points(Parser* parser, Axes axis,
                                           double angle) {
  S21Matrix rotation_matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  if (axis == AxisX) {
    rotation_matrix = create_rotation_X_matrix(angle);
  } else if (axis == AxisY) {
    rotation_matrix = create_rotation_Y_matrix(angle);
  } else if (axis == AxisZ) {
    rotation_matrix = create_rotation_Z_matrix(angle);
  }
  S21Matrix point(3, 3);
  for (size_t i = 0; i < parser->matrix_points.size(); i++) {
    point = parser->matrix_points[i];
    parser->matrix_points[i] = rotation_matrix * point;
    parser->matrix_points[i][3][0] = 1;
  }
}

void AffineTransformation::scale_points(Parser* parser, double scale_x,
                                        double scale_y, double scale_z) {
  double scale_ratio[3] = {scale_x, scale_y, scale_z};
  S21Matrix scale_matrix = create_scale_matrix(scale_ratio);
  S21Matrix point(3, 3);
  for (size_t i = 0; i < parser->matrix_points.size(); i++) {
    point = parser->matrix_points[i];
    parser->matrix_points[i] = scale_matrix * point;
    parser->matrix_points[i][3][0] = 1;
  }
  parser->min_max.x_max *= scale_x;
  parser->min_max.x_min *= scale_x;
  parser->min_max.y_max *= scale_y;
  parser->min_max.y_min *= scale_y;
  parser->min_max.z_max *= scale_z;
  parser->min_max.z_min *= scale_z;
}

void AffineTransformation::normalize_figure(s21::Parser* parser) {
  double delta_x = parser->min_max.x_max - parser->min_max.x_min;
  double delta_y = parser->min_max.y_max - parser->min_max.y_min;
  double delta_z = parser->min_max.z_max - parser->min_max.z_min;
  double delta_max = fabs(s21::max(delta_x, delta_y, delta_z));
  double scale = DELTA_VIEW / delta_max;
  this->scale_points(parser, scale, scale, scale);
  delta_x = parser->min_max.x_max - parser->min_max.x_min;
  delta_y = parser->min_max.y_max - parser->min_max.y_min;
  delta_z = parser->min_max.z_max - parser->min_max.z_min;
  double center_x = parser->min_max.x_min + delta_x / 2;
  double center_y = parser->min_max.y_min + delta_y / 2;
  double center_z = parser->min_max.z_min + delta_z / 2;
  for (size_t i = 0; i < parser->matrix_points.size(); i++) {
    parser->matrix_points[i][0][0] -= center_x;
    parser->matrix_points[i][1][0] -= center_y;
    parser->matrix_points[i][2][0] -= center_z;
  }
  parser->min_max.x_max -= center_x;
  parser->min_max.x_min -= center_x;
  parser->min_max.y_max -= center_y;
  parser->min_max.y_min -= center_y;
  parser->min_max.z_max -= center_z;
  parser->min_max.z_min -= center_z;
}

S21Matrix AffineTransformation::create_transfer_matrix(
    double* moving_coordinates) {
  S21Matrix matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  make_unit_matrix(matrix);
  for (int i = 0; i < DIMENSION_SPACE; i++) {
    matrix[i][ORDER_TRANSFER_MATRIX - 1] = moving_coordinates[i];
  }
  return matrix;
}

S21Matrix AffineTransformation::create_rotation_X_matrix(double angle) {
  S21Matrix matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  make_unit_matrix(matrix);
  double angle_in_rad = (M_PI * angle) / RAD_IN_DEGRE;
  matrix[1][1] = cos(angle_in_rad);
  matrix[1][2] = sin(angle_in_rad);
  matrix[2][1] = -matrix[1][2];
  matrix[2][2] = matrix[1][1];
  return matrix;
}

S21Matrix AffineTransformation::create_rotation_Y_matrix(double angle) {
  S21Matrix matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  make_unit_matrix(matrix);
  double angle_in_rad = (M_PI * angle) / RAD_IN_DEGRE;
  matrix[0][0] = cos(angle_in_rad);
  matrix[2][0] = sin(angle_in_rad);
  matrix[0][2] = -matrix[2][0];
  matrix[2][2] = matrix[0][0];
  return matrix;
}

S21Matrix AffineTransformation::create_rotation_Z_matrix(double angle) {
  S21Matrix matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  make_unit_matrix(matrix);
  double angle_in_rad = (M_PI * angle) / RAD_IN_DEGRE;
  matrix[0][0] = cos(angle_in_rad);
  matrix[0][1] = -sin(angle_in_rad);
  matrix[1][0] = -matrix[0][1];
  matrix[1][1] = matrix[0][0];
  return matrix;
}

S21Matrix AffineTransformation::create_scale_matrix(double* scale_ratio) {
  S21Matrix matrix(ORDER_TRANSFER_MATRIX, ORDER_TRANSFER_MATRIX);
  for (int i = 0; i < ORDER_TRANSFER_MATRIX; i++) {
    matrix[i][i] = scale_ratio[i];
  }
  return matrix;
}

void AffineTransformation::make_unit_matrix(S21Matrix& matrix) {
  for (int i = 0; i < ORDER_TRANSFER_MATRIX; i++) {
    matrix[i][i] = 1;
  }
}

double max(int x, int y, int z) {
  double res = x;
  if (y > res) {
    res = y;
  }
  if (z > res) {
    z = res;
  }
  return res;
}

}  // namespace s21