#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <string>

//! Classe Matriz
/*!
   Classe matriz. Representa uma matriz m x n. Onde m é o número de linhas e n é
   o número de colunas.
 */
class Matrix {
 public:
  //! Construtor
  /*!
     Inicializa uma matriz nula com as dimensões passadas por argumento. Recebe
     como argumentos os números de linhas e colunas da matriz.

     \param rows: Número de linhas da matriz (size_t).
     \param columns: Número de colunas da matriz (size_t).
   */
  Matrix(std::size_t rows, std::size_t columns);

  //! Destrutor
  /*!
     Destrutor da classe. Libera a memória alocada na inicialização do objeto.
   */
  ~Matrix(void);

  //! Popular Matriz.
  /*!
     Popula a matrix. Recebe uma string de 0s, 1s ou espaços em branco.

     Inicializa duas variáveis auxiliares linha e coluna. Itera pelos elementos
     da string. Se for um espaço em vazio, o ignora e segue para o próximo
     elemento. Caso contrário atribui ao elemento da matriz na posição (linha,
     coluna) o inteiro equivalente ao elemento na posição atual.

     Incrementa linha e coluna.

     Testa se é o último elemento da coluna. Caso positivo, zera variável
     auxiliar coluna e testa se a linha é a última. Caso positivo, sai do laço.

     \param data: string para popular a matriz.
   */
  void populate(const std::string& content);

  //! Getter Linhas
  /*!
     Getter do número de linhas da matriz.

     \return Número de linhas da matriz (std::size_t).
   */
  std::size_t rows(void) const;

  //! Getter Colunas
  /*!
     Getter do número de colunas da matriz.

     \return Número de colunas da matriz (std::size_t).
   */
  std::size_t columns(void) const;

  //! Sobrecarga do operador ()
  /*!
     Retorna o elemento no índice (row, column) da matriz.

     \param row: Linha (std::size_t).
     \param column: Coluna (std::size_t).

     \return Elemento na posição (row, column), inteiro.
   */
  int operator()(std::size_t row, std::size_t column) const;


  int& operator()(std::size_t row, std::size_t column);


 private:
  //! Linhas
  /*!
     Número de linhas da matriz. Tipo inteiro sem sinal size_t.
   */
  std::size_t rows_;

  //! Colunas
  /*!
     Altura da matrix. Tipo inteiro sem sinal size_t.
   */
  std::size_t columns_;

  //! Matriz
  /*!
     Matriz bidimensional de números inteiros. Pointeiro para ponteiro para
     inteiros (int **).
   */
  int** data_;

};

#endif
