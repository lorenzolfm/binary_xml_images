#include "parser.h"

#include <cstdint>
#include <iostream>
#include <regex>

#include "linked_stack.h"

Parser::Parser(void) { content = ""; }

Parser::Parser(std::string xml_content) : content(xml_content) {}

bool Parser::parse(void) {
  structures::LinkedStack<std::string> stack;

  std::size_t index{0u};
  std::size_t tag_begin_index{0u};
  std::size_t right_bracket_of_opening_tag_position{0u};
  std::size_t left_bracket_of_closing_tag_position{0u};

  char character{'0'};
  std::string tag{""};
  std::string name{""}, height{""}, width{""}, data{""};

  while (index < content.length()) {
    character = content[index];

    if (character == LEFT_BRACKET) {
      tag_begin_index = index;

      if (content[index + 1] == SLASH) {
        left_bracket_of_closing_tag_position = index;
      }
    }

    if (character == RIGHT_BRACKET) {
      tag = get_substr(tag_begin_index, index);

      if (tag[1] == SLASH) {
        std::string last_tag = stack.pop();

        if (!match(last_tag, tag)) {
          return false;
        }

        std::string tag_data =
            get_substr(right_bracket_of_opening_tag_position + 1,
                       left_bracket_of_closing_tag_position - 1);

        if (last_tag == "<name>") {
          name = tag_data;
        } else if (last_tag == "<height>") {
          height = tag_data;
        } else if (last_tag == "<width>") {
          width = tag_data;
        } else if (last_tag == "<data>") {
          data = tag_data;

          std::vector<std::string> image_components;

          image_components.push_back(name);
          image_components.push_back(height);
          image_components.push_back(width);
          image_components.push_back(data);

          parsed_data.push_back(image_components);
        }

      } else {
        right_bracket_of_opening_tag_position = index;

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

  return opening_tag_text.compare(closing_tag_text) == 0;
}

std::string Parser::get_substr(std::size_t start, std::size_t finish) {
  return content.substr(start, finish - start + 1);
}

std::vector<std::vector<std::string>> Parser::get_parsed_data(void) const {
  return parsed_data;
}

void Parser::set_content(std::string xml_content) { content = xml_content; }
