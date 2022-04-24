#ifndef ABSTRACT_TASK_H_
#define ABSTRACT_TASK_H_

#include <QBoxLayout>
#include <QWidget>

class AbstractTask : public QWidget {
  Q_OBJECT
 public:
  AbstractTask();

  const QBoxLayout* GetLayout() const;

  virtual bool CheckAnswer();

  virtual void GroupWidgetsInLayout();

 protected:
  QBoxLayout* layout_;
};

#endif  // ABSTRACT_TASK_H_
