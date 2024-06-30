#include "model.h"

std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
           std::vector<std::vector<int>>>
viewer::Model::ObjRead(const std::string file_name) {
  bool error = true;
  int count_vector = 0;
  int count_surface = 0;
  coordinates_.clear();
  surfaces_.clear();
  std::ifstream fin(file_name);
  std::string str;
  if (fin.is_open()) {
    while ((std::getline(fin, str))) {
      if (str[0] == 'v' && str[1] == ' ') {
        ExtractDoubleCoordinates(str, 1);
        ++count_vector;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        ExtractValueFaces(str);
        ++count_surface;
      }
    }
    fin.close();
  } else {
    error = false;
  }
  return {error, count_vector, count_surface, coordinates_, surfaces_};
}

void viewer::Model::ExtractDoubleCoordinates(const std::string str,
                                             int position) {
  std::istringstream iss{std::string(str)};
  double num1, num2, num3;
  int count = 0;
  while (count < 3) {
    ++position;
    iss.seekg(position, std::ios_base::beg);
    if (count == 0) iss >> num1;
    if (count == 1) iss >> num2;
    if (count == 2) iss >> num3;
    if (!iss.fail() || iss.eof()) {
      position = iss.tellg();
    }
    ++count;
  }
  coordinates_.push_back(std::make_tuple(num1, num2, num3));
}

void viewer::Model::ExtractValueFaces(const std::string str) {
  std::istringstream iss{std::string(str)};
  int num1;
  int position = 2;
  std::vector<int> surf;
  for (; position != -1;) {
    iss.seekg(position, std::ios_base::beg);
    iss >> num1;
    surf.push_back(num1);
    if (!iss.fail() || iss.eof()) {
      position = iss.tellg();
    }
    while (str[position] != ' ' && position < str.size()) {
      ++position;
    }
    if (position >= str.size()) break;
  }
  surfaces_.push_back(surf);
}

std::vector<std::tuple<double, double, double>> viewer::Model::Recalculation(
    viewer::Difference diff) {
  std::vector<std::tuple<double, double, double>> result;
  std::tuple<double, double, double> buf;
  for (int i = 0; i < coordinates_.size(); i++) {
    buf = {
        (std::get<0>(coordinates_[i]) + diff.get_x_move()) * diff.get_size(),
        (std::get<1>(coordinates_[i]) + diff.get_y_move()) * diff.get_size(),
        (std::get<2>(coordinates_[i]) + diff.get_z_move()) * diff.get_size()};

    double x = std::get<0>(buf);
    double y = std::get<1>(buf);
    double z = std::get<2>(buf);
    double xa = diff.get_x_alpha();
    double ya = diff.get_y_alpha();
    double za = diff.get_z_alpha();

    buf = {
        (x * cos(ya + za) + x * cos(ya - za) + 2 * z * sin(ya) -
         y * sin(ya + za) + y * sin(ya - za)) /
            2,
        (2 * y * cos(xa + za) - x * cos(xa + ya + za) + x * cos(xa - ya + za) +
         2 * y * cos(xa - za) - x * cos(xa + ya - za) + x * cos(xa - ya - za) -
         2 * z * sin(xa + ya) - 2 * z * sin(xa - ya) + 2 * x * sin(xa + za) +
         y * sin(xa + ya + za) - y * sin(xa - ya + za) - 2 * x * sin(xa - za) -
         y * sin(xa + ya - za) + y * sin(xa - ya - za)) /
            4,
        (2 * z * cos(xa + ya) + 2 * z * cos(xa - ya) - 2 * x * cos(xa + za) -
         y * cos(xa + ya + za) + y * cos(xa - ya + za) + 2 * x * cos(xa - za) +
         y * cos(xa + ya - za) - y * cos(xa - ya - za) + 2 * y * sin(xa + za) -
         x * sin(xa + ya + za) + x * sin(xa - ya + za) + 2 * y * sin(xa - za) -
         x * sin(xa + ya - za) + x * sin(xa - ya - za)) /
            4};
    result.push_back(buf);
  }
  return result;
}
