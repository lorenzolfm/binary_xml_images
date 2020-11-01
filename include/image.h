#ifndef IMAGE_H
#define IMAGE_H

#include "matrix.h"
#include <string>

class Image {
  public:

    Image() : matrix_(0, 0) {}

    std::string name(void) { return name_; }

    std::size_t height(void) { return height_; }

    std::size_t width(void) { return width_; }

    //std::string matrix(void) { return matrix_; }

    void name(std::string name) { name_ = name; }

    void height(std::size_t height) { height_ = height; }

    void width(std::size_t width) { width_ = width; }

    void matrix(std::string matrix) {
      Matrix content = Matrix(10, 10);
      matrix_ = content;
    }

  private:
    // Nome da imagem
    std::string name_;
    // Altura da imagem
    std::size_t height_;
    // Largura da imagem
    std::size_t width_;
    // Dados da imagem
    Matrix matrix_;
};

#endif
