#ifndef PARSER_H
#include <stdio.h>
#include <string.h>
#include <fstream>

class Tag {
  public:
    //! Constructor
    Tag();
    //! Return the only the tag name
    std::string getTagName(std::string);

  private:
      std::string tag_;
      std::string name_;
      std::string type_; // 0 for Opening tag 1 for closing tag
};

#endif
