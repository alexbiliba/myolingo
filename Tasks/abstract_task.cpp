#include "abstract_task.h"

#include "../constants.h"

AbstractTask::AbstractTask() : layout_(
    new QBoxLayout(QBoxLayout::Direction::TopToBottom)) {}

const QBoxLayout* AbstractTask::GetLayout() const {
  return layout_;
}

bool AbstractTask::CheckAnswer() {
  return false;
}

void AbstractTask::GroupWidgetsInLayout() {}

