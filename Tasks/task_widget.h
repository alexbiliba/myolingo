#ifndef TASK_WIDGET_H_
#define TASK_WIDGET_H_

#include <QBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

#include "pick_an_option_task.h"
#include "../constants.h"

class TaskWidget : public QWidget {
 Q_OBJECT
 public:
  TaskWidget();

  void AddNewTask(AbstractTask* task);
  void SetTask(int index);
  void ClearTaskWidget();

  QPushButton* GetExitButton() const;

  void UpdateAttempts();

  void StartTask();

  void GoodFinish();
  void BadFinish();


  bool last_game_win;
  int scores_won;

 public slots:
  void NextTask();

 private:
  QBoxLayout* layout_;

  std::vector<AbstractTask*> tasks_;

  QBoxLayout* top_layout_;
  QLabel* attempts_label_;

  QProgressBar* progress_bar_;
  QPushButton* ready_button_;
  QPushButton* exit_button_;

  QLabel* win_label_;
  QLabel* scores_label_;
  QLabel* loose_label_;

  int current_task_;
  int attempts_;

  void ClearLayout();
};

#endif  // TASK_WIDGET_H_
