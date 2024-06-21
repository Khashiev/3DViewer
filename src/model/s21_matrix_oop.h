#ifndef CPP4_3DViewer_V_2_0_1_MODEL_S21_MATRIX_OOP_H
#define CPP4_3DViewer_V_2_0_1_MODEL_S21_MATRIX_OOP_H

#include <algorithm>
#include <cmath>
#include <iostream>

#define defolt_rows 2
#define defolt_cols 2

// rows - строки
// cols - столбцы

namespace s21 {
class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  //выделение памяти под матрицу
  void Allocate();
  //отчистка памяти
  void Deallocate();
  //функция осуществляющая сложение и вычитание матриц
  void help_add_or_sub(const S21Matrix& other, int operation);

 public:
  //конструкторы и деструкторы

  //конструктор для создание дефолтной матрицы
  S21Matrix();
  //конструктор для создание матрицы заданной размерности
  S21Matrix(int rows, int cols);
  //конструктор копирования
  S21Matrix(const S21Matrix& other);
  //конструктор переноса
  S21Matrix(S21Matrix&& other);
  //деструктор
  ~S21Matrix();

  //основные функции
  //проверяет матрицы на равенство между собой
  bool EqMatrix(const S21Matrix& other) const;
  //суммирует две матрицы
  void SumMatrix(const S21Matrix& other);
  //вычитает из текущей матрицы другую
  void SubMatrix(const S21Matrix& other);
  //умножает текущую матрицу на число
  void MulNumber(const double num);
  // yмножает текущую матрицу на вторую
  void MulMatrix(const S21Matrix& other);
  // cоздает новую транспонированную матрицу из текущей и возвращает ее.
  S21Matrix Transpose();
  // вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает
  // ее.
  S21Matrix CalcComplements();
  //вычисляет определитель матрницы
  double Determinant();
  //вычисляет и возвращает обратную матрицу.
  S21Matrix InverseMatrix();

  //числовые операторы
  //+
  S21Matrix operator+(const S21Matrix& other) const;
  //-
  S21Matrix operator-(const S21Matrix& other) const;
  //* матрица на число
  S21Matrix operator*(const double num) const;
  //* на матрицу
  S21Matrix operator*(const S21Matrix& other) const;
  //==
  bool operator==(const S21Matrix& other) const noexcept;
  //=
  S21Matrix& operator=(const S21Matrix& other);
  //=
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  //+=
  S21Matrix& operator+=(const S21Matrix& other);
  //-=
  S21Matrix& operator-=(const S21Matrix& other);
  //*= матрица
  S21Matrix& operator*=(const S21Matrix& other);
  //*= число
  S21Matrix& operator*=(const double num);
  //оператор для доступа к элементу матрицы
  double* operator[](int row) const;
  //оператор возвращает элемент матрицы
  double& operator()(int row, int col) const;

  //вспмогательные функции

  //проверяет текущую матрицу на содержание inf или nan
  int nan_or_inf();
  //удаляет текущую матрицу и создает новую в которую записывает передаваемую
  //матрицу
  void cpy_mat(const S21Matrix& other);
  //определитель матрицы 2 на 2
  double help_minor(S21Matrix A);
  //создает матрицу которая получается из исходной путем вычеркивания строки и
  //сталбца
  void help_matrix_formation(S21Matrix* buf, int bani, int banj);
  //ставит нужные знаки для матрицы алгебраических дополнений
  void help_calc_complements();
  //проверяет текущую матрицу и переданную на содержание inf или nan
  int matrix_nan_or_inf(const S21Matrix& other);

  // accessor и mutator

  //возвращает кол-во строк
  int get_rows() const;
  //возвращает кол-во столбцов
  int get_cols() const;
  //изменяет кол-во строк
  void set_rows(int rows);
  //изменяет кол-во столбцов
  void set_cols(int cols);
};
}  // namespace s21
#endif