#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "abstract_controller.h"
#include "view.h"

class Controller : public AbstractController {
 public:
  Controller();

  void SetView(std::unique_ptr<View>&& view);
  void SetModel(std::shared_ptr<Model>&& model);

  const std::unique_ptr<View>& GetView() const;

  Model* GetModel() const override;

 private:
  std::unique_ptr<View> view_;
};

#endif  // CONTROLLER_H_
