#ifndef MENU_H_
#define MENU_H_

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class Menu : public QWidget {
  Q_OBJECT
 public:
  Menu();

  void ChangeScores(int scores);

 private:
  QBoxLayout* layout_;

  QLabel* scores_label_;

  QPushButton* pick_an_option_;
  QPushButton* input_answer_;
  QPushButton* audio_;
};

#endif  // MENU_H_
