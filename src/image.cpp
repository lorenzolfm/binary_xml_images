#include "image.h"

Image::Image(std::vector<std::string> tags) {
  name_ = tags[0];
  height_ = std::stoul(tags[1]);
  width_ = std::stoul(tags[2]);
  data_ = tags[3];
}
