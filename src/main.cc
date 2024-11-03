#include <QApplication>

#include "mainwindow.h"
#include "model/s21_affine_transformation.h"
#include "model/s21_parser.h"
#include "s21_controller.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  s21::Parser parser_obj;
  s21::Caretaker caretaker;

  s21::AffineTransformationFacade& transformation_obj =
      s21::AffineTransformationFacade::getInstance();
  s21::Controller& controller_obj = s21::Controller::getInstance(
      &parser_obj, &transformation_obj, &caretaker);
  MainWindow view(&controller_obj);
  view.show();
  return a.exec();
}
