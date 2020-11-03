#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <vector>

#include "image.h"
#include "image_processor.h"
#include "parser.h"

//! Classe Controlador
/*!
   Controlador da aplicação. Abstração de alto nível para fazer entrada,
   manipulação e saída dos dados
 */
class Controller {
 public:
  //! Construtor
  /*!
     Construtor. Recebe como argumento um ponteiro para caracter (char *) com o
     nome do arquivo que deseja-se contar os componentes conexos.

     \param file_name: Ponteiro para caracter (char *), nome do arquivo para
     realizar a contagem de componentes conexos
   */
  Controller(char* file_name);

  //! Parsear
  /*!
     Parsea o arquivo, utilizando o método parse no atributo parser.

     \return Booleano. True se XML é valido, False caso contrário.
   */
  bool parse(void);

  //! Contar Componentes Conexos
  /*!
     Faz a contagem dos componentes conexos para todas as imagens do XML. Printa
     resultado na terminal.
   */
  void count(void);

 private:
  //! Parser
  /*!
     Atributo privado parser, de tipo Parser
   */
  Parser parser;
};

#endif
