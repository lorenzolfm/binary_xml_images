#include <cstdint>
#include <regex>

#include "parser.h"
#include "linked_stack.h"

Parser::Parser(std::string xml_content) : content(xml_content) {}

bool Parser::parse(void) {
  structures::LinkedStack<std::string> stack;
  std::string tag{""};
  std::size_t tag_begin_index{0u};
  std::size_t index{0u};
  char character{'0'};

  while (index < content.length()) {
    character = content[index];

    if (character == LEFT_BRACKET) {
      tag_begin_index = index;
    }

    if (character == RIGHT_BRACKET) {
      tag = content.substr(tag_begin_index, index - tag_begin_index + 1);

      if (tag[1] == SLASH) {
        std::string last_tag = stack.pop();

        if (!match(last_tag, tag)) {
          return false;
        }
      } else {
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

// bool Parser::parse_file() {
// structures::LinkedStack<std::string> linked_stack;

// Image img;
// std::string tag{""};
// std::size_t tag_begin{0u};
// std::size_t left_bracket_of_closing_tag_position{0u};
// std::size_t right_bracket_of_opening_tag_position{0u};
// std::size_t index{0u};
// char content{' '};

// while (index < content_.length()) {
// content = content_[index];

// if (content == LEFT_BRACKET) {
// tag_begin = index;

// if (content_[index + 1] == SLASH) {
// left_bracket_of_closing_tag_position = index;
//}
//}

// if (content == RIGHT_BRACKET) {
// tag = extract_substr(tag_begin, index);

// if (tag[1] == SLASH) {
// std::string last_tag = linked_stack.pop();

// if (!match(tag, last_tag)) {
// return false;
//}

// std::size_t length_of_content = left_bracket_of_closing_tag_position -
// right_bracket_of_opening_tag_position -
// 1;

// std::string tag_data = content_.substr(
// right_bracket_of_opening_tag_position + 1, length_of_content);

////if (last_tag == "<name>") {
////img.name(tag_data);
////} else if (last_tag == "<height>") {
////img.height(std::stoi(tag_data));
////} else if (last_tag == "<width>") {
////img.width(std::stoi(tag_data));
////} else if (last_tag == "<data>") {
////img.data(tag_data);
//////std::cout << img.name() << " " << img.label() << std::endl;
////images_.push_back(img);
////}

//} else {
// right_bracket_of_opening_tag_position = index;

// linked_stack.push(tag);
//}
//}
// index++;
//}

// return linked_stack.empty();
//}

// std::string Parser::extract_substr(std::size_t begin, std::size_t index) {
// std::size_t length;
// length = index + 1 - begin;
// return content_.substr(begin, length);
//}

// void Parser::display() {
////for (auto i = 0; i < images_.size(); i++) {
////std::cout << images_[i]->name() << " " << images_[i]->label() << std::endl;
////}
//}
