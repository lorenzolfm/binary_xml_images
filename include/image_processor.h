#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include "matrix.h"

//! Classe Processador De Imagens
/*!
    Responsável por processar a imagem.
 */
class ImageProcessor {
 public:
  //! Construtor
  /*!
     Construtor do Processador De Imagens. Inicializa as matrizes E e R e popula
     a matrix E com os dados da imagem.

     \param image_data: Referência a uma string constante (const std::string&)
     que contém os dados da imagem.
     \param height: Altura da imagem, de tipo size_t.
     \param width: Largura da imagem, de tipo size_t.
   */
  ImageProcessor(const std::string& image_data, std::size_t height,
                 std::size_t width);

  //! Contar Componentes Conexos
  /*!
     Conta componentes conexos na matrix E que representa os dados da imagem.
   */
  void count_connected_components(void);

  //! Getter Contagem de Componentes Conexos
  /*!
     Getter do atributo privado conected_components_count.

     \return Inteiro que representa o número de componentes conexos da imagem.
   */
  int get_connected_components_count(void) const;

 private:
  //! Matrix R
  /*!
      Matriz que contém o resultado da rotulação, de tipo Matrix. Quantidade de
     componentes conexos é igual ao último e maior rótulo atribuído.
   */
  Matrix R;

  //! Matrix E
  /*!
     Matriz populada com os pixels da imagem, de tipo Matrix. Usada na contagem
     de componentes conexos.
   */
  Matrix E;

  //! Contagem de Componentes Conexos
  /*!
     Contagem da quantidade de componentes conexos na imagem, de tipo inteiro.
   */
  int connected_components_count;
};

#endif
