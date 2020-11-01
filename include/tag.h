#ifndef TAG_H
#define TAG_H

#include <string>

class Tag {
  public:
    Tag(void);

  private:
    // Nome da tag
    std::string name_;
    // Conteúdo da tag
    std::string content_;

}

#endif
