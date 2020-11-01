#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
  public:
    Image(void);
  private:
    // Nome da imagem
    std::string name_;
    // Altura da imagem
    std::size_t height;
    // Largura da imagem
    std::size_t width;
    // Dados da imagem
    int** matrix;
};

#endif
