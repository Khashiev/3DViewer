#ifndef CPP4_3DViewer_V_2_0_1_MODEL_S21_PARSER_H
#define CPP4_3DViewer_V_2_0_1_MODEL_S21_PARSER_H

#include <array>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "s21_matrix_oop.h"

namespace s21 {

struct Polygon {
  int pol[2];
};

struct MinMax {
  float x_min, x_max;
  float y_min, y_max;
  float z_min, z_max;
};

class Parser {
 public:
  Parser();
  ~Parser();

  void OpenFile(const std::string& filename);

  int GetVertexes();
  int GetPolygons();
  int GetError();
  MinMax GetMinMax();

  const std::vector<s21::S21Matrix>& GetMatrixPoints();
  const std::vector<Polygon>& GetArrayPolygons();

 private:
  int error;
  int vert_cnt;
  int pol_cnt;

  std::ifstream file;
  MinMax min_max;

  std::vector<s21::S21Matrix> matrix_points;
  std::vector<Polygon> polygons;

  s21::S21Matrix struct_vertex;
  Polygon line_of_polygon;

 private:
  void Clean();
  void ReadFile();
  void TakeVertex(std::string_view str);
  void PushVertexPoint(std::string_view str, size_t* pos, int number_cols);
  void TakePolygon(std::string_view str);
  int PushPolygonPoint(std::string_view str, size_t* pos);
  void FindMinMax(int number_cols, float value);
};
}  // namespace s21

#endif
