#include <QLabel>
#include "pick_an_option_task.h"

PickAnOptionTask::PickAnOptionTask() : AbstractTask(),
                                       ready_(new QPushButton("Ready")),
                                       answers_group_(new QButtonGroup),
                                       attempts_(new QLabel(
                                           "You have 4 attempts_")) {

  SetCorrectAnswer("Amilia");
  AddNewAnswer("Amilia");
  AddNewAnswer("Akilia");
  AddNewAnswer("Azilia");
}

void PickAnOptionTask::SetCorrectAnswer(const std::string& answer) {
  correct_answer_ = answer;
}

const std::string& PickAnOptionTask::GetCorrectAnswer() const {
  return correct_answer_;
}

void PickAnOptionTask::AddNewAnswer(const std::string& answer) {
  answera_str_.push_back(answer);
  answers_group_->addButton(new QCheckBox(answer.c_str()));
}

const std::vector<std::string>& PickAnOptionTask::GetAnswers() const {
  return answera_str_;
}

void PickAnOptionTask::SetQuestion(const std::string& question) {
  question_ = question;
}
const std::string& PickAnOptionTask::GetQuestion() const {
  return question_;
}

void PickAnOptionTask::SetAttemptsWidget(int attempts) {
  std::string new_text = "You have ";
  new_text += std::to_string(attempts);
  new_text += " attempts_count_";
  attempts_->setText(new_text.c_str());
}

void PickAnOptionTask::AttemptWasUsed() {

}

void PickAnOptionTask::TaskFailed() {

}
