#include <sstream>
#include <cstring>
#include <fstream>

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
