#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "abstract_controller.h"
#include "model.h"
#include "view.h"

class Controller : public {
 public:
  Controller();

 private:
  std::unique_ptr<View> view_;
  std::unique_ptr<Model> model_;
};

#endif  // CONTROLLER_H_
