#ifndef PARSER_H
#define PARSER_H

#include <string.h>

#include "linked_stack.h"

class Parser {
 public:
  Parser(std::string content);
  //! Verify semantics
  bool parse_file();
  //! Checks if a opening_tag matches a closing_tag
  bool match(std::string opening_tag, std::string closing_tag);

 private:
  std::string content_;
  structures::LinkedStack<std::string> linked_stack;
};

#endif
