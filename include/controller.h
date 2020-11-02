#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <vector>

#include "parser.h"
#include "image.h"
#include "image_processor.h"

class Controller {
  public:
  private:
    Parser parser;
    std::vector<Image> images;
    ImageProcessor processor;
};

#endif
