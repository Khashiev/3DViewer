#include "s21_affine_transformation.h"

namespace s21 {

AffineTransformation::AffineTransformation() {}

AffineTransformation::~AffineTransformation() {}

void AffineTransformation::move_point(S21Matrix& point,
                                      int* moving_coordinates) {
  S21Matrix transfer_matrix = create_transfer_matrix(moving_coordinates);
  std::cout << point.get_cols() << " " << point.get_rows() << std::endl;
  std::cout << transfer_matrix.get_cols() << " " << transfer_matrix.get_rows()
            << std::endl;
  point = transfer_matrix * point;
}

void AffineTransformation::rotation_point(S21Matrix& point, Axes axis,
                                          double angle) {
  S21Matrix rotation_matrix(4, 4);
  if (axis == AxisX) {
    rotation_matrix = create_rotation_X_matrix(angle);
  } else if (axis == AxisY) {
    rotation_matrix = create_rotation_Y_matrix(angle);
  } else if (axis == AxisZ) {
    rotation_matrix = create_rotation_Z_matrix(angle);
  }
  point = rotation_matrix * point;
}

S21Matrix AffineTransformation::create_transfer_matrix(
    int* moving_coordinates) {
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
  show_matrix(matrix);
  return matrix;
}

void AffineTransformation::make_unit_matrix(S21Matrix& matrix) {
  for (int i = 0; i < ORDER_TRANSFER_MATRIX; i++) {
    matrix[i][i] = 1;
  }
}

void show_matrix(s21::S21Matrix& matrix) {
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

}  // namespace s21