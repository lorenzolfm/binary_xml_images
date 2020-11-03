#include "matrix.h"

#include <stdexcept>

Matrix::Matrix(std::size_t rows, std::size_t columns) {
  rows_ = rows;
  columns_ = columns;

  data_ = new int*[rows_];
  for (auto i{0u}; i < rows_; i++) {
    data_[i] = new int[columns_];
    for (auto j{0u}; j < columns_; j++) {
      data_[i][j] = 0;
    }
  }
}

Matrix::~Matrix(void) {
  for (auto i{0u}; i < rows_; i++) {
    delete[] data_[i];
  }

  delete[] data_;
}

void Matrix::populate(const std::string& content) {
  std::size_t row{0}, column{0};

  for (const auto& character : content) {
    if (std::isspace(character)) {
      continue;
    }

    data_[row][column] = character - '0';

    column++;

    if (column == columns_) {
      column = 0;
      row++;

      if (row == rows_) {
        break;
      }
    }
  }
}

std::size_t Matrix::rows(void) const { return rows_; }

std::size_t Matrix::columns(void) const { return columns_; }

int Matrix::operator()(std::size_t row, std::size_t column) const {
  if (row >= rows_ || column >= columns_) {
    throw std::out_of_range("Matrix subscript out of bounds");
  }

  return data_[row][column];
}

int& Matrix::operator()(std::size_t row, std::size_t column) {
  if (row >= rows_ || column >= columns_) {
    throw std::out_of_range("Matrix subscript out of bounds");
  }

  return data_[row][column];
}
