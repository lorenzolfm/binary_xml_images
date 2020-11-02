#include <sstream>
#include <cstring>
#include <fstream>
#include <iostream>

#include "controller.h"

static char BASE_PATH[] = "assets/";

Controller::Controller(char * file_name) {
  char * full_path = strcat(BASE_PATH, file_name);

  std::ifstream file(full_path);

  if(!file.is_open()) {
    printf("ERROR: Unable to open file %s", full_path);
    exit(1);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();

  parser.set_content(buffer.str());
}

bool Controller::parse(void) {
  return parser.parse();
}

void Controller::count(void) {
  std::vector<std::vector<std::string>> xml_parsed_data = parser.get_parsed_data();

  for (auto i = 0; i < xml_parsed_data.size(); i++) {
    std::vector<std::string> image_data = xml_parsed_data[i];
    Image img(image_data);

    ImageProcessor processor(img.data(), img.height(), img.width());

    processor.count_connected_components();

    std::cout << img.name() << " " << processor.get_connected_components_count() << std::endl;
  }

}
