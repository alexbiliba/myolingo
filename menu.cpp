#include "menu.h"

Menu::Menu() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               scores_label_(new QLabel("")),
               pick_an_option_(new QPushButton("Pick an option")),
               input_answer_(new QPushButton("Input answer")),
               audio_(new QPushButton("Audio")) {
  layout_->addWidget(scores_label_);
  layout_->addWidget(pick_an_option_);
  layout_->addWidget(input_answer_);
  layout_->addWidget(audio_);
}

void Menu::ChangeScores(int scores) {
  std::string scores_text = "Scores: ";
  scores_text += std::to_string(scores);
  scores_label_->setText(scores_text.c_str());
}

QPushButton* Menu::GetPickAnOption() const {
  return pick_an_option_;
}
