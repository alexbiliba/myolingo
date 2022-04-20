#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "abstract_controller.h"
#include "model.h"
#include "view.h"

class Controller : public AbstractController {
 public:
  Controller();

  void SetView(std::unique_ptr<View>&& view);
  void SetModel(std::unique_ptr<Model>&& model);

  const std::unique_ptr<View>& GetView() const;

 private:
  std::unique_ptr<View> view_;
  std::unique_ptr<Model> model_;
};

#endif  // CONTROLLER_H_
