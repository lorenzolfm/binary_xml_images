#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>
#include <utility>

#include "matrix.h"
#include "linked_queue.h"

class Image {
 public:
  //Image() {}

  //Image(const Image& img) {
    //name_ = img.name_;
    //height_ = img.height_;
    //width_ = img.width_;
  //}

  ~Image() {}

  std::string name(void) { return name_; }

  std::size_t height(void) { return height_; }

  std::size_t width(void) { return width_; }

  void name(std::string name) { name_ = name; }

  void height(std::size_t height) { height_ = height; }

  void width(std::size_t width) { width_ = width; }

  void data(std::string image_data) { data_ = image_data; }

 private:
  //! Nome.
  /*!
     Nome da imagem. Tipo string.
   */
  std::string name_;

  //! Altura.
  /*!
     Altura da imagem. Tipo size_t.
   */
  std::size_t height_;

  //! Largura.
  /*!
     Largura da imagem. Tipo size_t.
   */
  std::size_t width_;

  //! Dados.
  /*!
     Dados da imagem. Tipo string.
   */
  std::string data_;
};

#endif
