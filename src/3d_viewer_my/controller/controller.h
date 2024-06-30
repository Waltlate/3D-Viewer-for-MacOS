#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_

#include <QMainWindow>
#include <cstring>

#include "../model/model.h"

namespace viewer {

class Controller {
 public:
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
  ObjRead(const QString file_name);
  std::vector<std::tuple<double, double, double>> Recalculation(
      viewer::Difference diff);

 private:
  viewer::Model model_;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
