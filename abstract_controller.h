#ifndef ABSTRACT_CONTROLLER_H_
#define ABSTRACT_CONTROLLER_H_

#include <memory>
#include <QObject>

#include "model.h"

class AbstractController : public QObject {
  Q_OBJECT
 public:
  AbstractController();

  virtual Model* GetModel() const;

 protected:
  std::shared_ptr<Model> model_;
};

#endif  // ABSTRACT_CONTROLLER_H_
