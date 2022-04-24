#ifndef SCORES_H_
#define SCORES_H_

#include <QContextMenuEvent>
#include <QLabel>
#include <QMenu>

class Scores : public QLabel {
 public:
  Scores();

  void contextMenuEvent(QContextMenuEvent* event) override;
  QMenu* GetMenu() const;

 private:
  QMenu* menu_;
};

#endif  // SCORES_H_
