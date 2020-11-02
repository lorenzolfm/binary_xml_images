#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "include/parser.h"
#include <stdexcept>

#include "include/controller.h"

using namespace std;

int main (int argc, char *argv[]) {
  char * file_name = argv[1];

  Controller controller(file_name);

  bool valid = controller.parse();

  if (!valid) printf("error\n");
  else {
    controller.count();
  }

  return 0;
}
