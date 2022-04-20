#include "abstract_controller.h"

AbstractController::AbstractController() {

}
Model* AbstractController::GetModel() const {
  return model_.get();
}
