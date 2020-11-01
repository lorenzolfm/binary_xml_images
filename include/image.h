#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>
#include <utility>

#include "linked_queue.h"

class Image {
 public:
  Image() {}

  Image(const Image& img) {
    name_ = img.name_;
    height_ = img.height_;
    width_ = img.width_;
    matrix_ = img.matrix_;
  }

  ~Image() {}

  std::string name(void) { return name_; }

  std::size_t height(void) { return height_; }

  std::size_t width(void) { return width_; }

  int label(void) { return label_; }

  void set_label(int label) { label_ = label; }

  void name(std::string name) { name_ = name; }

  void height(std::size_t height) { height_ = height; }

  void width(std::size_t width) { width_ = width; }

  void matrix(std::string matrix) {
    matrix_ = new int*[height_];
    for (std::size_t i = 0; i < height_; i++) {
      matrix_[i] = new int[width_];
      for (int j = 0; j < width_; j++) {
        matrix_[i][j] = 0;
      }
    }

    std::size_t i = 0, j = 0;
    for (const auto& car : matrix) {
      if (std::isspace(car)) {
        continue;
      }

      matrix_[i][j] = car - '0';

      if (++j >= width_) {
        j = 0;

        if (++i >= height_) {
          break;
        }
      }
    }

    int** r = new int*[height_];
    for (std::size_t i = 0; i < height_; i++) {
      r[i] = new int[width_];
      for (int j = 0; j < width_; j++) {
        r[i][j] = 0;
      }
    }

    i = 0, j = 0;
    for (const auto& car : matrix) {
      if (std::isspace(car)) {
        continue;
      }

      matrix_[i][j] = car - '0';

      if (++j >= width_) {
        j = 0;

        if (++i >= height_) {
          break;
        }
      }
    }

    using pixel = std::pair<int, int>;
    structures::LinkedQueue<std::pair<int, int>> paths;
    int label = 1;

    for (std::size_t i = 0; i < height_; i++) {
      for (std::size_t j = 0; j < width_; j++) {
        if (!r[i][j] && matrix_[i][j]) {
          r[i][j] = label;
          paths.enqueue({j, i});

          while (!paths.empty()) {
            const auto p = paths.dequeue();
            const auto x = p.first;
            const auto y = p.second;

            if (x - 1 >= 0 && !r[y][x - 1] && matrix_[y][x - 1]) {
              r[y][x - 1] = label;
              paths.enqueue({x - 1, y});
            }
            if (x + 1 < width_ && !r[y][x + 1] && matrix_[y][x + 1]) {
              r[y][x + 1] = label;
              paths.enqueue({x + 1, y});
            }
            if (y - 1 >= 0 && !r[y - 1][x] && matrix_[y - 1][x]) {
              r[y - 1][x] = label;
              paths.enqueue({x, y - 1});
            }
            if (y + 1 < height_ && !r[y + 1][x] && matrix_[y + 1][x]) {
              r[y + 1][x] = label;
              paths.enqueue({x, y + 1});
            }
          }
          label++;
        }
      }
    }

    for (std::size_t i = 0; i < height_; i++) {
      delete[] r[i];
    }

    delete[] r;

    for (std::size_t i = 0; i < height_; i++) {
      delete[] matrix_[i];
    }

    delete[] matrix_;

    //std::cout << label - 1 << std::endl;
    set_label(label - 1);
  }

 private:
  // Nome da imagem
  std::string name_;
  // Altura da imagem
  std::size_t height_;
  // Largura da imagem
  std::size_t width_;
  int label_;

  // Dados da imagem
  int** matrix_;
};

#endif
