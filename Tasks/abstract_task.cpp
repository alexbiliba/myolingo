#include "abstract_task.h"

#include "../constants.h"

AbstractTask::AbstractTask() : layout_(new QGridLayout()) {
  is_ready_ = false;
  is_correct_answer_ = false;
}

const QGridLayout* AbstractTask::GetLayout() const {
  return layout_;
}
