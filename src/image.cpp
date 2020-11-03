#include "image.h"

Image::Image(std::vector<std::string> tags) {
  name_ = tags[0];
  height_ = std::stoul(tags[1]);
  width_ = std::stoul(tags[2]);
  data_ = tags[3];
}

std::string Image::name(void) const { return name_; }

std::size_t Image::height(void) const { return height_; }

std::size_t Image::width(void) const { return width_; }

std::string Image::data(void) const { return data_; }
