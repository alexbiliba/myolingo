#include "view.h"

#include <utility>
#include <iostream>

View::View() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               main_menu_(new Menu),
               task_widget_(new TaskWidget) {
  setMinimumSize(700, 400);
}

void View::RunView() {
  CreateConnections();
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
  controller_->GetModel()->AddScores(task_widget_->scores_won);
  UpdateScores();
  main_menu_->show();
  UpdateScores();
  layout_->addWidget(main_menu_);
}

void View::OpenPickAnOption() {
  std::cerr << "\nWas opened pick-an-option task\n";
  ClearLayout();
  task_widget_->ClearTaskWidget();
// It makes controller        //
  PickAnOptionTask* new_task1 = new PickAnOptionTask;
  PickAnOptionTask* new_task2 = new PickAnOptionTask;
  PickAnOptionTask* new_task3 = new PickAnOptionTask;
  task_widget_->AddNewTask(new_task1);
  task_widget_->AddNewTask(new_task2);
  task_widget_->AddNewTask(new_task3);
//                            //
  task_widget_->show();
  layout_->addWidget(task_widget_);
  task_widget_->StartTask();
}

void View::ResetScores(QAction* action) {
  controller_->GetModel()->SetScores(0);
  UpdateScores();
}

void View::AddScores(int scores) {
  controller_->GetModel()->AddScores(scores);
  UpdateScores();
}

void View::ExitTask() {
  task_widget_->ClearTaskWidget();
  OpenMenu();
}

void View::CreateConnections() {
  connect(main_menu_->GetPickAnOption(), &QPushButton::clicked,
          this, &View::OpenPickAnOption);

  connect(main_menu_->GetScoresWidget()->GetMenu(),
          SIGNAL(triggered(QAction*)),
          this,
          SLOT(ResetScores(QAction*)));

  connect(task_widget_->GetExitButton(), &QPushButton::clicked,
          this, &View::ExitTask);
}

void View::ClearLayout() {
  while (!layout_->isEmpty()) {
    layout_->removeItem(layout_->itemAt(0));
  }
  main_menu_->hide();
  task_widget_->hide();
}

void View::UpdateScores() {
  main_menu_->ChangeScores(controller_->GetModel()->GetScores());
}
