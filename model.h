#ifndef MODEL_H_
#define MODEL_H_

#include "menu.h"

class Model {
 public:
  Model() = default;

  Menu* GetMainMenu() const;

 private:
  Menu* main_menu_{new Menu};
};

#endif  // MODEL_H_
