#ifndef TAG_H
#define TAG_H

#include <string>
#include <cstdint>

class Tag {
  public:
    void begin(std::size_t index) { tag_begin_index_= index; }
    void left_bracket_index(std::size_t index) {left_bracket_index_ = index;}
    void right_bracket_index(std::size_t index) { right_bracket_index_ = index;  }
  private:
    std::string tag_element;
    std::size_t tag_begin_index_;
    std::size_t left_bracket_index_;
    std::size_t right_bracket_index_;
};

#endif
