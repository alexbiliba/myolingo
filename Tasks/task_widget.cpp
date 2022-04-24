#include <iostream>
#include "task_widget.h"

TaskWidget::TaskWidget() : layout_(new QBoxLayout(
                           QBoxLayout::Direction::TopToBottom, this)),
                           top_layout_(new QBoxLayout(
                           QBoxLayout::Direction::LeftToRight)),
                           ready_button_(new QPushButton("Ready")),
                           exit_button_(new QPushButton("Return to menu")),
                           current_task_(0),
                           attempts_label_(new QLabel("")),
                           attempts_(constants::attempts_count),
                           last_game_win(false),
                           scores_won(0),
                           win_label_(new QLabel("Victory!")),
                           scores_label_(new QLabel("")),
                           loose_label_(new QLabel("Defeat..!")),
                           progress_bar_(new QProgressBar) {
  connect(ready_button_, &QPushButton::clicked,
          this, &TaskWidget::NextTask);
  loose_label_->setAlignment(Qt::AlignCenter);
  win_label_->setAlignment(Qt::AlignCenter);
  scores_label_->setAlignment(Qt::AlignCenter);
}

void TaskWidget::AddNewTask(AbstractTask* task) {
  task->GroupWidgetsInLayout();
  tasks_.push_back(task);
}

void TaskWidget::SetTask(int index) {
  if (index >= tasks_.size() || index < 0) {
    std::cerr << "TaskWidget: wrong index for SetTask\n";
    return;
  }
  ClearLayout();

  UpdateAttempts();

  top_layout_->addWidget(attempts_label_);
  top_layout_->addWidget(progress_bar_);
  top_layout_->addWidget(exit_button_);
  layout_->addLayout(top_layout_);
  layout_->addWidget(tasks_[index]);
  layout_->addWidget(ready_button_);

  attempts_label_->show();
  exit_button_->show();
  progress_bar_->show();
  tasks_[index]->show();
  ready_button_->show();
}

void TaskWidget::ClearLayout() {
  while (!layout_->isEmpty()) {
    layout_->removeItem(layout_->itemAt(0));
  }
  while (!top_layout_->isEmpty()) {
    top_layout_->removeItem(top_layout_->itemAt(0));
  }

  win_label_->hide();
  scores_label_->hide();
  loose_label_->hide();
  attempts_label_->hide();
  exit_button_->hide();
  progress_bar_->hide();
  for (auto task : tasks_) {
    task->hide();
  }
  ready_button_->hide();
}

void TaskWidget::ClearTaskWidget() {
  ClearLayout();
  tasks_.clear();
  current_task_ = 0;
  attempts_ = constants::attempts_count;
  last_game_win = false;
}

QPushButton* TaskWidget::GetExitButton() const {
  return exit_button_;
}

void TaskWidget::NextTask() {
  bool answer_is_right = tasks_[current_task_]->CheckAnswer();
  std::cerr << "Answer state: " << answer_is_right << '\n';

  if (!answer_is_right) {
    attempts_--;
    if (attempts_ == 0) {
      std::cerr << "You lost!\n";
      last_game_win = false;
      BadFinish();
      return;
    }
    UpdateAttempts();
  }

  current_task_++;
  if (current_task_ >= tasks_.size()) {
    last_game_win = true;
    std::cerr << "You won!\n";
    GoodFinish();
  } else {
    progress_bar_->setValue(progress_bar_->value() + 1);
    SetTask(current_task_);
  }
}

void TaskWidget::GoodFinish() {
  ClearLayout();

  scores_won = rand() % 30 + 27;

  std::string scores_text = "+ ";
  scores_text += std::to_string(scores_won);
  scores_text += " scores :))";
  scores_label_->setText(scores_text.c_str());

  scores_label_->show();
  win_label_->show();
  exit_button_->show();

  layout_->addWidget(win_label_);
  layout_->addWidget(scores_label_);
  layout_->addWidget(exit_button_);
}
void TaskWidget::BadFinish() {
  ClearLayout();

  loose_label_->show();
  exit_button_->show();

  layout_->addWidget(loose_label_);
  layout_->addWidget(exit_button_);
}

void TaskWidget::UpdateAttempts() {
  std::string attempts_text = "Attempts: ";
  attempts_text += std::to_string(attempts_).c_str();
  attempts_label_->setText(attempts_text.c_str());
}

void TaskWidget::StartTask() {
  progress_bar_->setMinimum(0);
  progress_bar_->setMaximum(tasks_.size());
  progress_bar_->setValue(0);
  scores_won = 0;
  SetTask(0);
}
