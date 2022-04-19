#ifndef APP_H_
#define APP_H_

#include "controller.h"
#include "view.h"

#include <memory>

class App {
 public:
  App();

  void Run();

 private:
  std::unique_ptr<Controller> m_controller_;
};

#endif  // APP_H_
