#include "controller.h"

#include <utility>

Controller::Controller() {
}

void Controller::SetModel(std::unique_ptr<Model>&& model) {
  assert(model != nullptr);
  model_ = std::move(model);
}

void Controller::SetView(std::unique_ptr<View>&& view) {
  assert(view != nullptr);
  view_ = std::move(view);
}

const std::unique_ptr<View>& Controller::GetView() const {
  return view_;
}
