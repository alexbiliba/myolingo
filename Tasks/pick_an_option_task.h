#ifndef PICK_AN_OPTION_TASK_H_
#define PICK_AN_OPTION_TASK_H_

#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

#include "abstract_task.h"

class PickAnOptionTask : public AbstractTask {
  Q_OBJECT
 public:
  PickAnOptionTask();

  void SetQuestion(const std::string& question);
  const std::string& GetQuestion() const;

  void SetCorrectAnswer(const std::string& answer);
  const std::string& GetCorrectAnswer() const;

  void AddNewAnswer(const std::string& answer);
  const std::vector<std::string>& GetAnswers() const;

  bool CheckAnswer() override;

  void GroupWidgetsInLayout() override;

 signals:
 public slots:

 private:
  std::string question_;
  std::string correct_answer_;
  std::vector<std::string> answers_str_;

  QBoxLayout* layout_;
  QLabel* question_label_;
  QButtonGroup* answers_group_;
  std::vector<QCheckBox*> answers_vector_;

};

#endif  // PICK_AN_OPTION_TASK_H_
