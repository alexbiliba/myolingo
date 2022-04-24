#include <iostream>
#include "model.h"

Model::Model() : settings_(new QSettings("StudentBiliba", "Myolingo")) {
  scores_ = settings_->value("Scores").toInt();
  std::cerr << "Scores: " << scores_ << '\n';
}

int Model::GetScores() const {
  return scores_;
}

void Model::SetScores(int scores) {
  scores_ = scores;
  settings_->setValue("Scores", scores);
}

void Model::AddScores(int scores) {
  SetScores(scores_ + scores);
}
