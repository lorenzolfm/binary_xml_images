#include "image_processor.h"

#include <utility>

#include "linked_queue.h"

ImageProcessor::ImageProcessor(const std::string& image_data,
                               std::size_t height, std::size_t width)
    : E(height, width), R(height, width) {
  E.populate(image_data);
  connected_components_count = 1;
}

void ImageProcessor::count_connected_components(void) {
  using pixel = std::pair<int, int>;
  structures::LinkedQueue<pixel> paths;
  int label = 1;

  for (std::size_t row{0}; row < E.rows(); row++) {
    for (std::size_t column{0}; column < E.columns(); column++) {
      if (E(row, column) && !R(row, column)) {
        R(row, column) = label;
        paths.enqueue({column, row});

        while (!paths.empty()) {
          std::pair<int, int> pair = paths.dequeue();
          int x = pair.first;
          int y = pair.second;

          if ((x - 1 >= 0) && (!R(y, x - 1) && E(y, x - 1))) {
            R(y, x - 1) = label;
            paths.enqueue({x - 1, y});
          }
          if ((x + 1 < E.columns()) && (!R(y, x + 1) && E(y, x + 1))) {
            R(y, x + 1) = label;
            paths.enqueue({x + 1, y});
          }
          if ((y - 1 >= 0) && (!R(y - 1, x) && E(y - 1, x))) {
            R(y - 1, x) = label;
            paths.enqueue({x, y - 1});
          }
          if ((y + 1 < E.rows()) && (!R(y + 1, x) && E(y + 1, x))) {
            R(y + 1, x) = label;
            paths.enqueue({x, y + 1});
          }
        }
        label++;
      }
    }
  }
  connected_components_count = label;
}

int ImageProcessor::get_connected_components_count(void) const {
  return connected_components_count - 1;
}
