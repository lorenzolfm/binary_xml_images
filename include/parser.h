#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <vector>

#include "linked_stack.h"
#include "image.h"

class Parser {
 public:
  Parser(std::string content);
  //! Verify semantics
  bool parse_file();
  //! Checks if a opening_tag matches a closing_tag
  bool match(std::string opening_tag, std::string closing_tag);


  void display();
 private:
  std::string extract_substr(std::size_t begin, std::size_t index);

  std::string content_;
  std::vector<Image> images_;

  static const char LEFT_BRACKET = '<';
  static const char RIGHT_BRACKET = '>';
  static const char SLASH = '/';
};

#endif
