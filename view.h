#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <QBoxLayout>
#include <QGroupBox>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

#include "abstract_controller.h"

class View : public QWidget {
  Q_OBJECT
 public:
  View();

  void SetController(const std::shared_ptr<AbstractController>& controller);

 private:
  QBoxLayout* main_layout_;
  std::shared_ptr<AbstractController> controller_;
};

#endif  // VIEW_H_
