#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <string>

class Image {
 public:

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
