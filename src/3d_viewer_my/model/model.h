#ifndef CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "../diff/difference.h"

namespace viewer {

class Model {  // obj? file name is model. that could confuse
 public:
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
  ObjRead(const std::string file_name);
  std::vector<std::tuple<double, double, double>> Recalculation(
      viewer::Difference diff);

 private:
  void ExtractDoubleCoordinates(const std::string str, int position);
  void ExtractValueFaces(const std::string str);

  std::vector<std::tuple<double, double, double>> coordinates_;
  std::vector<std::vector<int>> surfaces_;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
