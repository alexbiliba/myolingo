#include "app.h"

App::App(std::unique_ptr<Model>&& model,
         std::unique_ptr<View>&& view,
         std::shared_ptr<Controller>&& controller) {
  controller_ = std::move(controller);
  view->SetController(controller_);
  controller_->SetModel(std::move(model));
  controller_->SetView(std::move(view));
}

void App::Run() {
  controller_->GetView()->show();
}
