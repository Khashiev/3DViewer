#include "s21_parser.h"

namespace s21 {

void Parser::Clean() {
  matrix_points.clear();
  polygons.clear();

  vert_cnt = 0;
  pol_cnt = 0;

  min_max.x_min = 0;
  min_max.x_max = 0;
  min_max.y_min = 0;
  min_max.y_max = 0;
  min_max.z_min = 0;
  min_max.z_max = 0;
}

void Parser::OpenFile(const std::string& filename) {
  Clean();
  error = 0;

  file.open(filename);
  if (file.is_open()) {
    ReadFile();
    file.close();
  } else {
    error = 1;
  }
}

void Parser::ReadFile() {
  std::string reading_str;

  vertex.set_rows(4);
  vertex.set_cols(1);

  while (!file.eof() && !error) {
    std::getline(file, reading_str);
    std::string_view str = reading_str;

    if (str.find("v ") == 0) {
      vert_cnt++;
      TakeVertex(str);
      matrix_points.push_back(vertex);
    }

    if (str.find("f ") == 0) {
      pol_cnt++;
      TakeFacet(str);
    }
  }

  if (error) {
    Clean();
  }
}

void Parser::TakeVertex(std::string_view str) {
  int number_cols = 0;

  for (size_t i = 0; i < str.size(); i++) {
    if ((std::isdigit(str[i]) || str[i] == '-') && str[i - 1] == ' ' &&
        number_cols < 4) {
      number_cols++;
      PushMatrixPoint(str, &i, number_cols);
    }
  }

  if (number_cols < 3) {
    error = 2;
  }
}

void Parser::PushMatrixPoint(std::string_view str, size_t* pos,
                             int number_cols) {
  std::string number;
  size_t iter = *pos;

  while (std::isdigit(str[iter]) || str[iter] == '.' || str[iter] == '-') {
    number += str[iter++];
  }
  *pos = iter;

  double res = std::stod(number);
  if (number_cols == 1) {
    vertex[0][0] = res;
  } else if (number_cols == 2) {
    vertex[1][0] = res;
  } else if (number_cols == 3) {
    vertex[2][0] = res;
  }

  FindMinMax(number_cols, res);
}

void Parser::FindMinMax(int number_cols, double value) {
  if (number_cols == 1) {
    min_max.x_min = std::min(value, min_max.x_min);
    min_max.x_max = std::max(value, min_max.x_max);
  } else if (number_cols == 2) {
    min_max.y_min = std::min(value, min_max.y_min);
    min_max.y_max = std::max(value, min_max.y_max);
  } else if (number_cols == 3) {
    min_max.z_min = std::min(value, min_max.z_min);
    min_max.z_max = std::max(value, min_max.z_max);
  }
}

void Parser::TakeFacet(std::string_view str) {
  size_t cnt_lines = 0;
  for (size_t i = 0; i < str.size() && !error; i++) {
    if ((std::isdigit(str[i]) || str[i] == '-') && str[i - 1] == ' ') {
      cnt_lines++;

      facet.pol[0] = PushPolygonPoint(str, &i);
      facet.pol[1] = facet.pol[0];

      polygons.push_back(facet);

      if (cnt_lines > 1) {
        polygons[polygons.size() - 2].pol[1] = facet.pol[1];
      }
    }
  }

  polygons[polygons.size() - 1].pol[1] =
      polygons[polygons.size() - cnt_lines].pol[0];
}

int Parser::PushPolygonPoint(std::string_view str, size_t* pos) {
  std::string number;
  size_t iter = *pos;

  while (std::isdigit(str[iter]) || str[iter] == '-') {
    number += str[iter++];
  }

  *pos = iter;
  int res = std::stoi(number);

  if (res < 0) {
    if (res >= (-1) * vert_cnt) {
      res = vert_cnt + res;
    } else {
      error = 3;
    }
  } else if (res > 0) {
    if (res > vert_cnt) {
      error = 3;
    } else {
      --res;
    }
  }

  return res;
}

int Parser::GetVertexes() { return vert_cnt; }
int Parser::GetPolygons() { return pol_cnt; }
int Parser::GetError() { return error; }
MinMax Parser::GetMinMax() { return min_max; }

const std::vector<s21::S21Matrix>& Parser::GetMatrixPoints() {
  return matrix_points;
}
const std::vector<Polygon>& Parser::GetArrayPolygons() { return polygons; }

}  // namespace s21
