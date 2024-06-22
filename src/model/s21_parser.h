#ifndef CPP4_3DViewer_V_2_0_1_MODEL_S21_PARSER_H
#define CPP4_3DViewer_V_2_0_1_MODEL_S21_PARSER_H

#include <vector>

#include "s21_matrix_oop.h"

namespace s21 {
class Parser {
 public:
  Parser();
  ~Parser();
  std::vector<s21::S21Matrix> matrix_points;

 private:
};
}  // namespace s21

#endif
