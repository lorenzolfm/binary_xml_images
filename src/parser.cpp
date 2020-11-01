#include <parser.h>
#include "image.h"
#include <stdio.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

static const char LEFT_BRACKET = '<';
static const char RIGHT_BRACKET = '>';
static const char SLASH = '/';

Parser::Parser(std::string content) : content_(content) {}

bool Parser::parse_file() {
  Image img;
  std::string tag;
  std::size_t tag_begin;

  auto index = 0u;
  char content;

  auto left_bracket_of_closing_tag_position = 0u;
  auto right_bracket_of_opening_tag_position = 0u;

  while (index < content_.length()) {
    content = content_[index];

    if (isTagElement(content, LEFT_BRACKET)) {
      tag_begin = index;

      if (content_[index + 1] == SLASH) {
        left_bracket_of_closing_tag_position = index;
      }
    }

    if (isTagElement(content, RIGHT_BRACKET)) {
      tag = assembly_tag(tag_begin, index);

      if (isTagElement(tag[1], SLASH)) {
        std::string last_tag = linked_stack.pop();

        if (!match(tag, last_tag)) {
          return false;
        }

        std::size_t length_of_content = left_bracket_of_closing_tag_position - right_bracket_of_opening_tag_position - 1;
        std::string tag_content = content_.substr(right_bracket_of_opening_tag_position + 1, length_of_content);

        if (last_tag == "<name>") {
          img.name(tag_content);
        } else if (last_tag == "<height>") {
          img.height(std::stoi(tag_content));
        } else if (last_tag == "<width>") {
          img.width(std::stoi(tag_content));
        } else if (last_tag == "<data>") {
          //img.matrix(tag_content);
          images_.push_back(img);
        }

      } else {
        right_bracket_of_opening_tag_position = index;
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

bool Parser::isTagElement(const char& content_at_index,
                          const char& tag_element) {
  return content_at_index == tag_element;
}

std::string Parser::assembly_tag(std::size_t begin, std::size_t index) {
  std::size_t length;
  length = index + 1 - begin;
  return content_.substr(begin, length);
}

void Parser::display() {
  for (auto i = 0; i < images_.size(); i++) {
    std::cout << images_[i].name() << std::endl;
    std::cout << images_[i].height() << std::endl;
    std::cout << images_[i].width() << std::endl;
    //std::cout << images_[i].matrix() << std::endl;
    std::cout << "" << std::endl;
  }
}
