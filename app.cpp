#include "app.h"

App::App() {
  m_controller_ = std::make_unique<Controller>(new Controller);
}
