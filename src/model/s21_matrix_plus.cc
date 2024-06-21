#include "s21_matrix_oop.h"

//конструкторы и деструкторы
namespace s21 {

S21Matrix::S21Matrix() : rows_(defolt_rows), cols_(defolt_cols) { Allocate(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ > 0 && cols_ > 0) {
    Allocate();
  } else {
    throw std::length_error("Size array error");
  }
}

S21Matrix::~S21Matrix() { Deallocate(); }

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

void S21Matrix::Allocate() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::Deallocate() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}

//основные функции

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool res = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    res = false;
  }
  for (int i = 0; i < this->rows_ && res != false; i++) {
    for (int j = 0; j < this->cols_ && res != false; j++) {
      if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        res = false;
      }
    }
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix dimensions do not match");
  } else if (matrix_nan_or_inf(other)) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  }
  help_add_or_sub(other, 1);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix dimensions do not match");
  } else if (matrix_nan_or_inf(other)) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  }
  help_add_or_sub(other, -1);
}

void S21Matrix::MulNumber(const double num) {
  if (nan_or_inf() || std::isnan(num) || std::isinf(num)) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (matrix_nan_or_inf(other)) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  } else if (this->cols_ != other.rows_) {
    throw std::logic_error("Matrix dimensions do not match");
  }
  double res = 0.0;
  S21Matrix buffer(rows_, other.get_cols());
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      res = 0;
      for (int k = 0; k < this->cols_; k++) {
        res = res + this->matrix_[i][k] * other.matrix_[k][j];
      }
      buffer[i][j] = res;
    }
  }
  cpy_mat(buffer);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix trans(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      trans[j][i] = (*this)[i][j];
    }
  }
  return trans;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw std::logic_error("Matrix dimensions do not match");
  } else if (nan_or_inf()) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  }
  S21Matrix result(this->rows_, this->rows_);
  if (this->rows_ > 1) {
    S21Matrix result(this->rows_, this->rows_);
    S21Matrix bufmat(this->rows_ - 1, this->rows_ - 1);
    double buf_det = 0.0;
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->rows_; j++) {
        help_matrix_formation(&bufmat, i, j);
        buf_det = bufmat.Determinant();
        result[i][j] = buf_det;
      }
    }
    result.help_calc_complements();
    return result;
  }
  result.set_cols(1);
  result.set_rows(1);
  result[0][0] = 1.0;
  return result;
}

double S21Matrix::Determinant() {
  double res = 0;
  int sign = 1;
  if (this->rows_ != this->cols_) {
    throw std::logic_error("Invalid matrix");
  } else if (nan_or_inf()) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  }
  if (this->rows_ == 3) {
    for (int i = 0; i < this->rows_; i++) {
      S21Matrix buf(this->rows_ - 1, this->cols_ - 1);
      if ((i + 2) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      help_matrix_formation(&buf, 0, i);
      res = res + sign * (*this)[0][i] * help_minor(buf);
    }
  } else if (this->rows_ == 2) {
    res = help_minor(*this);
  } else if (this->rows_ == 1) {
    res = (*this)[0][0];
  } else if (this->rows_ > 3) {
    for (int i = 0; i < this->rows_; i++) {
      S21Matrix buf(this->rows_ - 1, this->cols_ - 1);
      help_matrix_formation(&buf, 0, i);
      double minor = buf.Determinant();
      if ((i + 2) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      res = res + sign * (*this)[0][i] * minor;
    }
  }

  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->nan_or_inf()) {
    throw std::invalid_argument("matrix element cannot be nan or inf");
  } else if (this->cols_ != this->rows_) {
    throw std::logic_error("Invalid matrix");
  }
  double det = this->Determinant();
  if (det == 0) {
    throw std::logic_error("The determinant cannot be zero");
  }
  S21Matrix result(this->rows_, this->cols_);
  result = this->CalcComplements();
  result = result.Transpose();
  det = 1.0 / det;
  result.MulNumber(det);
  return result;
}

//числовые операторы

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix res = (*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix res = (*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix res = (*this);
  res.MulNumber(num);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix res = (*this);
  res.MulMatrix(other);
  return res;
}

bool S21Matrix::operator==(const S21Matrix &other) const noexcept {
  return this->EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    cpy_mat(other);
  }
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double *S21Matrix::operator[](int row) const {
  if (this->rows_ <= row || this->rows_ < 0) {
    throw std::out_of_range("There is no element with such an index");
  }
  return matrix_[row];
}

double &S21Matrix::operator()(int row, int col) const {
  if (this->rows_ <= row || this->cols_ <= col) {
    throw std::out_of_range("There is no element with such an index");
  } else if (row < 0 || col < 0) {
    throw std::length_error(
        "The dimension of the matrix must be greater than zero");
  }
  return matrix_[row][col];
}

//вспмогательные функции

void S21Matrix::help_calc_complements() {
  int sign = -1;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if ((i + j + 2) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      (*this)[i][j] *= sign;
    }
  }
}

double S21Matrix::help_minor(S21Matrix A) {
  double res = 0;
  res = A[0][0] * A[1][1] - A[1][0] * A[0][1];
  return res;
}

void S21Matrix::help_matrix_formation(S21Matrix *buf, int bani, int banj) {
  int i1 = 0, j1 = 0;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (i != bani && j != banj) {
        (*buf)[j1][i1] = (*this)[i][j];
        i1++;
        if (i1 == buf->rows_) {
          j1++;
          i1 = 0;
        }
      }
    }
  }
}

int S21Matrix::get_rows() const { return this->rows_; }

int S21Matrix::get_cols() const { return this->cols_; }

void S21Matrix::set_rows(int rows) {
  int trow = this->rows_;
  if (rows <= 0) {
    throw std::length_error("Size array error");
  }
  if (rows != trow) {
    S21Matrix buf(rows, cols_);
    for (int i = 0; i < rows && i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i < trow) {
          buf[i][j] = (*this)[i][j];
        } else {
          buf[i][j] = 0;
        }
      }
    }
    cpy_mat(buf);
  }
}

void S21Matrix::set_cols(int cols) {
  if (cols <= 0) {
    throw std::length_error("Size array error");
  }
  if (cols != this->cols_) {
    S21Matrix buf(rows_, cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_ && j < cols; j++) {
        if (j < this->cols_) {
          buf[i][j] = (*this)[i][j];
        } else {
          buf[i][j] = 0;
        }
      }
    }
    cpy_mat(buf);
  }
}

void S21Matrix::cpy_mat(const S21Matrix &other) {
  Deallocate();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  Allocate();
  for (int i = 0; i < rows_ && i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)[i][j] = other[i][j];
    }
  }
}

void S21Matrix::help_add_or_sub(const S21Matrix &other, int operation) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] =
          this->matrix_[i][j] + operation * other.matrix_[i][j];
    }
  }
}

int S21Matrix::nan_or_inf() {
  int res = 0;
  for (int i = 0; i < this->rows_ && res == 0; i++) {
    for (int j = 0; j < this->cols_ && res == 0; j++) {
      if (std::isnan((*this)[i][j]) || std::isinf((*this)[i][j])) {
        res = 1;
      }
    }
  }
  return res;
}

int S21Matrix::matrix_nan_or_inf(const S21Matrix &other) {
  int res = 0;
  for (int i = 0; i < this->rows_ && res == 0; i++) {
    for (int j = 0; j < this->cols_ && res == 0; j++) {
      if (std::isnan((*this)[i][j]) || std::isinf((*this)[i][j])) {
        res = 1;
      }
    }
  }
  for (int i = 0; i < other.rows_ && res == 0; i++) {
    for (int j = 0; j < other.cols_ && res == 0; j++) {
      if (std::isnan(other[i][j]) || std::isinf(other[i][j])) {
        res = 1;
      }
    }
  }
  return res;
}

}  // namespace s21