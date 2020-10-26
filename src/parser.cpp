#include <parser.h>
#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>

static const char LEFT_BRACKET = '<';
static const char RIGHT_BRACKET = '>';
static const char SLASH = '/';

Parser::Parser(std::string content) : content_(content) {}

bool Parser::parse_file() {
  std::string tag;
  std::size_t tag_begin;
  std::size_t tag_length;

  auto index = 0u;
  while (index < content_.length()) {
    if (content_[index] == LEFT_BRACKET) {
      tag_begin = index;
    }

    if (content_[index] == RIGHT_BRACKET) {
      tag_length = index + 1 - tag_begin;
      tag = content_.substr(tag_begin, tag_length);

      if (tag[1] == SLASH) {
        std::string last_tag = linked_stack.pop();
        if (!match(tag, last_tag)) {
          return false;
        }
      } else {
        linked_stack.push(tag);
      }
    }
    index++;
  }

  return linked_stack.empty();
}

bool Parser::match(std::string opening_tag, std::string closing_tag) {
  std::regex reg("\\W");

  std::string opening_tag_text = std::regex_replace(opening_tag, reg, "");
  std::string closing_tag_text = std::regex_replace(closing_tag, reg, "");

  bool match = opening_tag_text.compare(closing_tag_text);

  return match == 0;
}
