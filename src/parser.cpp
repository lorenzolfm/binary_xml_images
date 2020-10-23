#include <parser.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <regex>
#include <stdexcept>

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

        if (tag[1] == SLASH) {
          std::string last_tag = linked_stack.pop();
          if(!match(last_tag, tag))
            return false;
        } else {
          linked_stack.push(tag);
        }
      }
    }
  }

  if (!linked_stack.empty()) {
    return false;
  }

  return true;
}

bool Parser::match(std::string opening_tag, std::string closing_tag) {
  std::regex reg ("\\W");
  bool match = std::regex_replace(opening_tag, reg, "")
    .compare(std::regex_replace(closing_tag, reg, ""));

  return match == 0;
}
