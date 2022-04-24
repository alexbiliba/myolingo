#include <iostream>
#include <QApplication>

#include "app.h"

int main(int argc, char* argv[]) {
  QApplication m_app(argc, argv);

  std::shared_ptr<Model> model(new Model);
  std::unique_ptr<View> view(new View);
  std::shared_ptr<Controller> controller(new Controller);

  App app(std::move(model), std::move(view), std::move(controller));
  app.Run();

  return QApplication::exec();
}