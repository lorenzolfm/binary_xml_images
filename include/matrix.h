#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <string>

class Matrix {
 public:
   Matrix(std::size_t height, std::size_t width) {
     width_ = width;
     height_ = height;
   };
  int connected_components();
 private:
  std::size_t width_;
  std::size_t height_;
};

#endif
