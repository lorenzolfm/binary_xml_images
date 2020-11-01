#ifndef TAG_H
#define TAG_H

#include <string>
#include <cstdint>

class Tag {
  public:
  private:
    std::string tag_element;
    std::size_t tag_begin_index;
    std::size_t left_bracket_index;
    std::size_t right_bracket_index;
}

#endif
