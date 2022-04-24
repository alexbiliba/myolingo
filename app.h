#ifndef APP_H_
#define APP_H_

#include "controller.h"
#include "view.h"

#include <memory>

class App {
 public:
  App(std::shared_ptr<Model>&& model,
      std::unique_ptr<View>&& view,
      std::shared_ptr<Controller>&& controller);

  void Run();

 private:
  std::shared_ptr<Controller> controller_;
};

#endif  // APP_H_
