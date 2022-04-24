#ifndef TASK_WIDGET_H_
#define TASK_WIDGET_H_

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class TaskWidget : public QWidget {
 Q_OBJECT
 public:
  TaskWidget();
 public slots:
 private:
  QBoxLayout* layout_;

//  QLabel* scores_widget_;

  QPushButton* button_;
};

#endif  // TASK_WIDGET_H_
