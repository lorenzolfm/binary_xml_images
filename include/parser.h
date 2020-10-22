#ifndef PARSER_H
#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <fstream>

class Parser {
  public:
    Parser(std::ifstream &file);
    //! Verify semantics
    bool parse_file();
    //! Checks if a opening_tag matches a closing_tag
    bool match(std::string opening_tag, std::string closing_tag);

  private:
      std::ifstream &file_;
      structures::LinkedList<std::string> linked_list;
};

#endif
