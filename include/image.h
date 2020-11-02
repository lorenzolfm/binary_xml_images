#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <string>
#include <vector>

class Image {
 public:
  //! Construtor
  /*!
     Constrói uma instância do classe Imagem. Recebe como parâmetros um vetor de
     strings que contém as todos os elementos do XML relevantes para uma imagem.

     \param tags: Vetor de strings que contém todos os elementos do XML
     (elemento = tag abertura + conteúdo + tag fechamento) relevantes para o
     objeto imagem
   */
  Image(std::vector<std::string> tags);

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
