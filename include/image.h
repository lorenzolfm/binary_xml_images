#ifndef IMAGE_H
#define IMAGE_H

//#include "matrix.h"
#include <string>

class Image {
 public:

   //~Image() {
   //}
  std::string name(void) { return name_; }

  std::size_t height(void) { return height_; }

  std::size_t width(void) { return width_; }

  void name(std::string name) { name_ = name; }

  void height(std::size_t height) { height_ = height; }

  void width(std::size_t width) { width_ = width; }

  void matrix(std::string matrix) {
    matrix_ = new int*[height_];
    for (std::size_t i = 0; i < height_; i++) {
      matrix_[i] = new int[width_];
      for (int j = 0; j < width_; j++) {
        matrix_[i][j] = 0;
      }
    }

    for (std::size_t i = 0; i < height_; i++) {
      delete[] matrix_[i];
    }

    delete[] matrix_;
  }

 private:
  // Nome da imagem
  std::string name_;
  // Altura da imagem
  std::size_t height_;
  // Largura da imagem
  std::size_t width_;
  // Dados da imagem
  int** matrix_;
};

#endif
