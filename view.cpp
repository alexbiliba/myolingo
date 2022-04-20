#include "view.h"

#include <utility>
#include <iostream>

View::View() : main_layout_(new QBoxLayout(
                   QBoxLayout::Direction::TopToBottom, this)) {
  std::cerr << "View was created\n";
  main_layout_->addWidget(new QPushButton("example_button"));
}

void View::SetController(
    const std::shared_ptr<AbstractController>& controller) {
  assert(controller != nullptr);
  controller_ = controller;
}
