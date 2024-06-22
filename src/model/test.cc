// #include <iostream>

// #include "s21_affine_transformation.h"
// #include "s21_matrix_oop.h"
// #include "s21_parser.h"

// int main() {
//   s21::Parser parser;
//   s21::S21Matrix her(4, 1);
//   double gogo[3] = {3, 1, 3};
//   for (int i = 0; i < 3; i++) {
//     her[0][0] = gogo[0] + i;
//     her[1][0] = gogo[1] + i;
//     her[2][0] = gogo[2] + i;
//     her[3][0] = 1;
//     s21::show_matrix(her);
//     std::cout << std::endl;
//     parser.matrix_points.push_back(her);
//   }
//   s21::AffineTransformation trans;
//   trans.move_points(&parser, 2, 3, -1);
//   for (int i = 0; i < parser.matrix_points.size(); i++) {
//     s21::show_matrix(parser.matrix_points[i]);
//     std::cout << std::endl;
//   }

//   // s21::show_matrix(matrix);
//   return 0;
// }