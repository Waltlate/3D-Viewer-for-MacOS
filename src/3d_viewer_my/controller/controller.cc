#include "controller.h"

std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
           std::vector<std::vector<int>>>
viewer::Controller::ObjRead(const QString file_name) {
  return model_.ObjRead(file_name.toStdString().c_str());
}

std::vector<std::tuple<double, double, double>>
viewer::Controller::Recalculation(viewer::Difference diff) {
  return model_.Recalculation(diff);
}
