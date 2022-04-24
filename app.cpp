#include "app.h"

App::App(std::shared_ptr<Model>&& model,
         std::unique_ptr<View>&& view,
         std::shared_ptr<Controller>&& controller) {
  controller_ = std::move(controller);
  view->SetController(controller_);
  controller_->SetModel(model);
  controller_->SetView(std::move(view));
}

void App::Run() {
  controller_->GetView()->RunView();
}
