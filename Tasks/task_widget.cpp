#include "task_widget.h"

TaskWidget::TaskWidget() : layout_(new QBoxLayout(
                           QBoxLayout::Direction::TopToBottom, this)),
                           button_(new QPushButton("Example")){
  layout_->addWidget(button_);
}
