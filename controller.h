#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "abstract_controller.h"
#include "model.h"
#include "view.h"

class Controller : public {
 public:
  Controller();

  void SetView(std::unique_ptr<View>&& view);
  void SetModel(std::unique_ptr<Model>&& model);

 private:
  std::unique_ptr<View> view_ = nullptr;
  std::unique_ptr<Model> model_ = nullptr;
};

#endif  // CONTROLLER_H_
