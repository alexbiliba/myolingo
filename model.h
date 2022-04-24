#ifndef MODEL_H_
#define MODEL_H_

#include <QSettings>

#include "menu.h"

class Model {
 public:
  Model();

  int GetScores() const;
  void SetScores(int scores);

 private:
  QSettings* settings_;
  int scores_;
};

#endif  // MODEL_H_
