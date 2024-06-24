#include <gtest/gtest.h>

#include "../model/s21_matrix_oop.h"
#include "../model/s21_parser.h"

TEST(Parser, test_1) {
  s21::Parser pars;
  std::string filename = "tests/obj/cube.obj";
  pars.OpenFile(filename);

  EXPECT_EQ(pars.GetVertexes(), 8);
  EXPECT_EQ(pars.GetPolygons(), 12);
}

TEST(Parser, test_2) {
  s21::Parser pars;
  std::string filename = "blabla";
  pars.OpenFile(filename);

  EXPECT_EQ(pars.GetError(), 1);
}

TEST(Parser, test_3) {
  s21::Parser pars;
  std::string filename = "tests/obj/parser.txt";
  pars.OpenFile(filename);
  std::vector<s21::S21Matrix> matrix = pars.GetMatrixPoints();

  // std::vector<s21::S21Matrix> matrix2;
  // for (int j = 0; j < pars.GetVertexes(); j++) {
  //   s21::S21Matrix res_matrix(4, 1);
  //   for (int i = 0, k = 1; i < 3; i++, k += 2) {
  //     res_matrix[i][0] = k;
  //   }
  //   matrix2.push_back(res_matrix);
  // }
  // ASSERT_TRUE(matrix == matrix2);

  s21::S21Matrix res_matrix(4, 1);
  for (int i = 0, k = 1; i < 3; i++, k += 2) res_matrix[i][0] = k;
  EXPECT_EQ(matrix.at(0), res_matrix);

  for (int i = 0, k = 7; i < 3; i++, k += 2) res_matrix[i][0] = k;
  EXPECT_EQ(matrix.at(1), res_matrix);

  for (int i = 0, k = 13; i < 3; i++, k += 2) res_matrix[i][0] = k;
  EXPECT_EQ(matrix.at(2), res_matrix);

  for (int i = 0, k = 19; i < 3; i++, k += 2) res_matrix[i][0] = k;
  EXPECT_EQ(matrix.at(3), res_matrix);

  // std::cout << pars.GetArrayPolygons().at(0).pol[1] << '\n';
}
