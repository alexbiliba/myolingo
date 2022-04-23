#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <QBoxLayout>
#include <QWidget>

#include "abstract_controller.h"
#include "Tasks/pick_an_option_task.h"

class View : public QWidget {
  Q_OBJECT
 public:
  View();

  void SetController(const std::shared_ptr<AbstractController>& controller);

 public slots:
  void OpenMenu();

 private:
  void ClearLayout() const;

  QBoxLayout* layout_;
  Menu* main_menu_;
  std::shared_ptr<AbstractController> controller_;
};

#endif  // VIEW_H_
