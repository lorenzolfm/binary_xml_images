#include "matrix.h"

Matrix::Matrix(std::size_t rows, std::size_t columns) {
  rows_ = rows;
  columns_ = columns;

  matrix = new int*[rows_];
  for (auto i{0u}; i < rows_; i++) {
    matrix[i] = new int[columns_];
    for (auto j{0u}; j < columns_; j++) {
      matrix[i][j] = 0;
    }
  }
}

Matrix::~Matrix(void) {
  for (auto i{0u}; i < rows_; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void Matrix::populate(const std::string& content) {
  std::size_t row{0}, column{0};

  for (const auto& character : content) {
    if (std::isspace(character)) {
      continue;
    }

    matrix[row][column] = character - '0';

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
