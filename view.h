#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <QBoxLayout>
#include <QPainter>
#include <QWidget>

#include "abstract_controller.h"
#include "menu.h"
#include "Tasks/pick_an_option_task.h"
#include "Tasks/task_widget.h"

class View : public QWidget {
  Q_OBJECT
 public:
  View();

  void RunView();

  void SetController(const std::shared_ptr<AbstractController>& controller);

  void paintEvent(QPaintEvent* event) override;

 public slots:
  void OpenMenu();
  void OpenPickAnOption();
  void ResetScores(QAction* action);
  void AddScores(int scores);

 private:
  void CreateConnections();
  void ClearLayout();
  void UpdateScores();

  QBoxLayout* layout_;
  Menu* main_menu_;
  TaskWidget* task_widget_;
  std::shared_ptr<AbstractController> controller_;
};

#endif  // VIEW_H_
