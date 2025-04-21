#include <iomanip>  // std::setw()
#include <iostream>
#include <stdexcept>  // std::out_of_range()
#include <string>

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix() {
  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column) matrix_[row][column] = 0;
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& matrix) {
  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column)
      matrix_[row][column] = matrix.get(row, column);
}

TwoDimensionMatrix::TwoDimensionMatrix(
    const MatrixElement (&matrix)[size_][size_]) {
  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column)
      matrix_[row][column] = matrix[row][column];
}

MatrixElement TwoDimensionMatrix::get(size_t row, size_t column) const {
  return matrix_[row][column];
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(
    const TwoDimensionMatrix& matrix) {
  if (this == &matrix) return *this;

  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column)
      matrix_[row][column] = matrix.get(row, column);

  return *this;
}

std::ostream& operator<<(std::ostream& out, const TwoDimensionMatrix& matrix) {
  for (size_t row = 0; row < matrix.size(); ++row) {
    for (size_t column = 0; column < matrix.size(); ++column)
      out << std::setw(4) << matrix.get(row, column);
    out << '\n';
  }

  return out;
}

std::istream& operator>>(std::istream& in, TwoDimensionMatrix& matrix) {
  for (size_t row = 0; row < matrix.size(); ++row)
    for (size_t column = 0; column < matrix.size(); ++column)
      in >> matrix.matrix_[row][column];

  return in;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column)
      matrix_[row][column] *= number;

  return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(
    const TwoDimensionMatrix& matrix) const {
  TwoDimensionMatrix result;
  for (size_t row = 0; row < size(); ++row)
    for (size_t column = 0; column < size(); ++column)
      result.matrix_[row][column] =
          matrix_[row][column] && matrix.get(row, column);

  return result;
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i) { return matrix_[i]; }

const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
  return matrix_[i];
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1,
                             const TwoDimensionMatrix& matrix2) {
  TwoDimensionMatrix result;
  for (size_t row = 0; row < matrix1.size(); ++row)
    for (size_t column = 0; column < matrix1.size(); ++column)
      result[row][column] = matrix1.get(row, column) + matrix2.get(row, column);

  return result;
}