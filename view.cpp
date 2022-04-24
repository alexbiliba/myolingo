#include "view.h"

#include <utility>
#include <iostream>

View::View() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               main_menu_(new Menu),
               task_widget_(new TaskWidget) {
  std::cerr << "View was created\n";
  connect(main_menu_->GetPickAnOption(), &QPushButton::clicked,
          this, &View::OpenPickAnOption);
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

void View::paintEvent(QPaintEvent* event) {
}

void View::OpenMenu() {
  ClearLayout();
  main_menu_->show();
  main_menu_->ChangeScores(controller_->GetModel()->GetScores());
  layout_->addWidget(main_menu_);
}

void View::OpenPickAnOption() {
  std::cerr << "Was opened pick-an-option task\n";
  ClearLayout();
  task_widget_->show();
  layout_->addWidget(task_widget_);
}

void View::ClearLayout() {
  while (!layout_->isEmpty()) {
    std::cerr << "Was deleted item\n";
    layout_->removeItem(layout_->itemAt(0));
  }
  main_menu_->hide();
  task_widget_->hide();
}
