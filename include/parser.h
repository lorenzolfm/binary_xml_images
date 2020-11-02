#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include <iostream>

//! Classe Parser
/*!
   Classe responsável por fazer a validação da string que representa o arquivo
   XML e por separar as tags que representam uma imagem.
 */
class Parser {
 public:
  //! Construtor
  /*!
     Construtor. Tem como parâmetro o conteúdo do arquivo XML em formato de
     string.

     \param xml_content. Conteúdo do arquivo XML em formato de string. Usado
     para inicializar o atributro privado content.
   */
  Parser(std::string xml_content);

  //! Analísa Conteúdo.
  /*!
     Verifica o aninhamento e fechamento das tags e separa os elementos
     pertencentes a cada imagem.

     \return true: Se o aninhamento e fechamento das tags está correto.
     \return false: Se o aninhamento ou fechamento das tags está incorreto.
   */
  bool parse(void);

  //! Tags Combinam.
  /*!
     Verifica, através do uso de uma regex, se as tags de abertura e fechamento
     do elemento combinam.

     \param opening_tag: Referência constante a string (const std::string&) que
     representa a tag de abertura. \param closing_tag: Referência constante a
     string (const std::sting&) que representa a tag de fechamento.

     \return true: Retorna verdadeiro caso a tag de abertura e a tag de
     fechamento combinem.
     \return false: Retorna falso caso a tag de abertura e
     a tag de fechamento não combinem
   */
  bool match(const std::string& opening_tag, const std::string& closing_tag);

  std::vector<std::vector<std::string>> get_parsed_data(void);

 private:
  //! Getter Substring
  /*!
     Extrai uma substring da string content, dado um ínicio e um final.

     \param start: Índice de início da substring (std::size_t).
     \param finish: Índice final da substring (std::size_t).

     \return Retorna a substring extraída (std::string).
   */
  std::string get_substr(std::size_t start, std::size_t finish);

  //! Conteúdo.
  /*!
     Conteúdo do arquivo XML em formato de string.
   */
  std::string content;

  //! Dados "Parseados"
  /*!
     Vetor de vetor de strings. Cada elemento seu armazena um conjunto de
     vetores com as informações relevantes de cada imagem.
   */
  std::vector<std::vector<std::string>> parsed_data;

  //! Símbolo de abertura de elemento.
  /*!
     Símbolo de abertura de elemento de XML. Variável de classe, char constante
     e estático (static const char).
   */
  static const char LEFT_BRACKET = '<';

  //! Símbolo de fechamento de elemento.
  /*!
     Símbolo de fechamento de elemento de XML. Variável de classe, char
     constante e estático (static const char).
   */
  static const char RIGHT_BRACKET = '>';

  //! Símbolo de sinalização para tags de fechamento.
  /*!
     Símbolo de sinalização de tags de fechamento. Uma tag que contém como
     segundo caracter uma barra é uma tag de fechamento. Váriavel de classe,
     char constante e estático (static const char).
   */
  static const char SLASH = '/';
};

#endif
