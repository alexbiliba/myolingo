#include "scores.h"

Scores::Scores() : menu_(new QMenu(this)) {
  setAlignment(Qt::AlignCenter);

  menu_->addAction("Reset scores");
}

void Scores::contextMenuEvent(QContextMenuEvent* event) {
  menu_->exec(event->globalPos());
}

QMenu* Scores::GetMenu() const {
  return menu_;
}
