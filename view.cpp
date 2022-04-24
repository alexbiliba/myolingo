#include "view.h"

#include <utility>
#include <iostream>

View::View() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               main_menu_(new Menu) {
  std::cerr << "View was created\n";
}

void View::RunView() {
  show();
  OpenMenu();
}

void View::SetController(
    const std::shared_ptr<AbstractController>& controller) {
  assert(controller != nullptr);
  controller_ = controller;
}

void View::OpenMenu() {
  ClearLayout();
  main_menu_->ChangeScores(controller_->GetModel()->GetScores());
  layout_->addWidget(main_menu_);
}

void View::ClearLayout() const {
  while (!layout_->isEmpty()) {
    layout_->removeItem(layout_->itemAt(0));
  }
}
