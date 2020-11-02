#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include "image.h"
#include "matrix.h"
#include "parser.h"

//! Classe Processador De Imagens
/*!
    Responsável por processar a imagem.
 */
class ImageProcessor {
 public:
 private:
  //! Matrix R
  /*!
      Matriz que contém o resultado da rotulação, de tipo Matrix. Quantidade de componentes
     conexos é igual ao último e maior rótulo atribuído.
   */
  Matrix R;
  //! Matrix E
  /*!
     Matriz populada com os pixels da imagem, de tipo Matrix. Usada na contagem de componentes conexos.
   */
  Matrix E;

  //! Contagem de Componentes Conexos
  /*!
     Contagem da quantidade de componentes conexos na imagem, de tipo inteiro.
   */
  int conected_components_count;
};

#endif
