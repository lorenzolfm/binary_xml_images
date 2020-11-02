#include "parser.h"

#include <cstdint>
#include <iostream>
#include <regex>

#include "linked_stack.h"

Parser::Parser(std::string xml_content) : content(xml_content) {}

bool Parser::parse(void) {
  structures::LinkedStack<std::string> stack;
  std::string tag{""};
  std::size_t tag_begin_index{0u};
  std::size_t index{0u};
  char character{'0'};

  std::size_t opening_tag_lbracket_position{0u};
  std::string name_tag{""};
  std::string height_tag{""};
  std::string width_tag{""};
  std::string data_tag{""};

  while (index < content.length()) {
    character = content[index];

    if (character == LEFT_BRACKET) {
      tag_begin_index = index;
    }

    if (character == RIGHT_BRACKET) {
      tag = get_substr(tag_begin_index, index);

      if (tag[1] == SLASH) {
        std::string last_tag = stack.pop();

        if (!match(last_tag, tag)) {
          return false;
        }

        if (last_tag == "<name>") {
          name_tag = get_substr(opening_tag_lbracket_position, index);
        } else if (last_tag == "<height>") {
          height_tag = get_substr(opening_tag_lbracket_position, index);
        } else if (last_tag == "<width>") {
          width_tag = get_substr(opening_tag_lbracket_position, index);
        } else if (last_tag == "<data>") {
          data_tag = get_substr(opening_tag_lbracket_position, index);

          std::vector<std::string> image_components;
          image_components.push_back(name_tag);
          image_components.push_back(height_tag);
          image_components.push_back(width_tag);
          image_components.push_back(data_tag);

          parsed_data.push_back(image_components);
        }

      } else {
        opening_tag_lbracket_position = tag_begin_index;
        stack.push(tag);
      }
    }
    index++;
  }
  return stack.empty();
}

bool Parser::match(const std::string& opening_tag,
                   const std::string& closing_tag) {
  std::regex reg("\\W");

  std::string opening_tag_text = std::regex_replace(opening_tag, reg, "");
  std::string closing_tag_text = std::regex_replace(closing_tag, reg, "");

  bool match = opening_tag_text.compare(closing_tag_text);

  return match == 0;
}

std::string Parser::get_substr(std::size_t start, std::size_t finish) {
  return content.substr(start, finish - start + 1);
}
