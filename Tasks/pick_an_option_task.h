#ifndef PICK_AN_OPTION_TASK_H_
#define PICK_AN_OPTION_TASK_H_

#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

#include "abstract_task.h"

class PickAnOptionTask : public AbstractTask {
 public:
  PickAnOptionTask();

  void SetQuestion(const std::string& question);
  const std::string& GetQuestion() const;

  void SetCorrectAnswer(const std::string& answer);
  const std::string& GetCorrectAnswer() const;

  void AddNewAnswer(const std::string& answer);
  const std::vector<std::string>& GetAnswers() const;

  void SetAttemptsWidget(int attempts);

 signals:
  void AttemptWasUsed();
  void TaskFailed();

 public slots:

 private:
  std::string question_;
  std::string correct_answer_;
  std::vector<std::string> answera_str_;

  QPushButton* ready_;
  QButtonGroup* answers_group_;

  QLabel* attempts_;

};

#endif  // PICK_AN_OPTION_TASK_H_
