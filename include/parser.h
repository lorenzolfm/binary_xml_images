#ifndef PARSER_H
#define PARSER_H

#include <string.h>

#include "linked_stack.h"
#include "image.h"

class Parser {
 public:
  Parser(std::string content);
  //! Verify semantics
  bool parse_file();
  //! Checks if a opening_tag matches a closing_tag
  bool match(std::string opening_tag, std::string closing_tag);

 private:
  //! Check if content_at_index is equal to tag_element
  bool isTagElement(const char& content_at_index, const char& tag_element);

  std::string assembly_tag(std::size_t begin, std::size_t index);

  std::string content_;
  structures::LinkedStack<std::string> linked_stack;
};

#endif
