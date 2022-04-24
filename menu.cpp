#include "menu.h"

Menu::Menu() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               scores_widget_(new Scores()),
               pick_an_option_(new QPushButton("Pick an option")),
               input_answer_(new QPushButton("Input answer")),
               audio_(new QPushButton("Audio")) {
  layout_->addWidget(scores_widget_);
  layout_->addWidget(pick_an_option_);
  layout_->addWidget(input_answer_);
  layout_->addWidget(audio_);
}

void Menu::ChangeScores(int scores) {
  std::string scores_text = "Scores: ";
  scores_text += std::to_string(scores);
  scores_widget_->setText(scores_text.c_str());
}

QPushButton* Menu::GetPickAnOption() const {
  return pick_an_option_;
}

Scores* Menu::GetScoresWidget() {
  return scores_widget_;
}
