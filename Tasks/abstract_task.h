#ifndef ABSTRACT_TASK_H_
#define ABSTRACT_TASK_H_

#include <QGridLayout>

class AbstractTask {
 public:
  AbstractTask();

  const QGridLayout* GetLayout() const;

 protected:
  QGridLayout* layout_;

  bool is_ready_;
  bool is_correct_answer_;
};

#endif  // ABSTRACT_TASK_H_
