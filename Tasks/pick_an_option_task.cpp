#include <QLabel>
#include "pick_an_option_task.h"

PickAnOptionTask::PickAnOptionTask() : AbstractTask(),
                                       layout_(new QBoxLayout(
                                       QBoxLayout::Direction::TopToBottom,
                                       this)),
                                       answers_group_(new QButtonGroup) {
  SetQuestion("Who ... she?");
  SetCorrectAnswer("is");
  AddNewAnswer("am");
  AddNewAnswer("is");
  AddNewAnswer("are");
}

void PickAnOptionTask::SetCorrectAnswer(const std::string& answer) {
  correct_answer_ = answer;
}
const std::string& PickAnOptionTask::GetCorrectAnswer() const {
  return correct_answer_;
}

void PickAnOptionTask::AddNewAnswer(const std::string& answer) {
  answers_str_.push_back(answer);
  QCheckBox* new_check_box = new QCheckBox(answer.c_str());
  answers_group_->addButton(new_check_box);
  answers_vector_.push_back(new_check_box);
}
const std::vector<std::string>& PickAnOptionTask::GetAnswers() const {
  return answers_str_;
}

void PickAnOptionTask::SetQuestion(const std::string& question) {
  question_ = question;
  question_label_ = new QLabel(question.c_str());
}
const std::string& PickAnOptionTask::GetQuestion() const {
  return question_;
}

bool PickAnOptionTask::CheckAnswer() {
  QCheckBox* answered_box = dynamic_cast<QCheckBox*>(
      answers_group_->checkedButton());
  if (answered_box == nullptr) {
    return false;
  }
  return answered_box->text() == correct_answer_.c_str();
}

void PickAnOptionTask::GroupWidgetsInLayout() {
  layout_->addWidget(question_label_);
  for (auto answer : answers_vector_) {
    layout_->addWidget(answer);
  }
}
