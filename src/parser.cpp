#include "includes/parser.h"
#include "string.h"
#include "stdio.h"
#include "fstream"

static const char LEFT_BRACKET = '<';
static const char RIGHT_BRACKET = '>';
static const char SLASH = '/';

Parser::Parser(std::ifstream &file) : file_(file) {}

bool Parser::parse_file() {
  std::string line;
  std::string tag;
  std::size_t tag_begin; 
  std::size_t tag_length;
  while (getline(file_, line)) {
    for (size_t i = 0; i < line.size(); i++) {
      if(line[i] == LEFT_BRACKET) {
        tag_begin = i;
      }

      if (line[i] == RIGHT_BRACKET) { 
        tag_length = i + 1 - tag_begin;
        tag = line.substr(tag_begin, tag_length);

        printf("%s", tag.c_str());
        if (tag[1] == SLASH) { 
          std::string last_tag = linked_list.pop_back();


        }
      } else {
        linked_list.push_back(tag);
      }
    }
  }

  if (!linked_list.empty()) {
    return false;
  }

  return true;
}

bool Parser::match(std::string opening_tag, std::string closing_tag) {
  // retrive the content of each tag and compare
}
