#include "menu.h"

Menu::Menu() : layout_(new QBoxLayout(QBoxLayout::Direction::TopToBottom,
                                      this)),
               pick_an_option_(new QPushButton("Pick an option")),
               input_answer_(new QPushButton("Input answer")),
               audio_(new QPushButton("Audio")) {
  layout_->addWidget(pick_an_option_);
  layout_->addWidget(input_answer_);
  layout_->addWidget(audio_);
}
