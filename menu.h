#ifndef MENU_H_
#define MENU_H_

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>

class Menu : public QWidget {
  Q_OBJECT
 public:
  Menu();

 private:
  QBoxLayout* layout_;

  QPushButton* pick_an_option_;
  QPushButton* input_answer_;
  QPushButton* audio_;
};

#endif  // MENU_H_
