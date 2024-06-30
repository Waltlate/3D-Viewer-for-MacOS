#ifndef CPP4_3DVIEWER_V2_0_VIEW_COLOR_H_
#define CPP4_3DVIEWER_V2_0_VIEW_COLOR_H_

#include <QDoubleSpinBox>

namespace viewer {

class ColorPallette {
 public:
  ColorPallette() {
    red_ = 0;
    blue_ = 1;
    green_ = 0;
    alpha_ = 0;
    name_ = "Saphire";
  }

  ColorPallette(QString name, GLfloat red, GLfloat blue, GLfloat green,
                GLfloat alpha) {
    red_ = red;
    blue_ = blue;
    green_ = green;
    alpha_ = alpha;
    name_ = name;
  }

  void set_pallette(QColor color) {
    red_ = color.redF();
    blue_ = color.blueF();
    green_ = color.greenF();
    alpha_ = color.alphaF();
  }

  QString get_name() { return name_; }
  GLfloat get_red() { return red_; }
  GLfloat get_blue() { return blue_; }
  GLfloat get_green() { return green_; }
  GLfloat get_alpha() { return alpha_; }

 private:
  GLfloat red_;
  GLfloat blue_;
  GLfloat green_;
  GLfloat alpha_;
  QString name_;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_VIEW_COLOR_H_