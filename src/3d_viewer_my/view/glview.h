#ifndef CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_

#define GL_SILENCE_DEPRECATION

#include <QDoubleSpinBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QScrollBar>
#include <QWheelEvent>

#include "../controller/controller.h"
#include "../diff/difference.h"  // view part has model's file
#include "color.h"
#include "memento/memento.h"
#include "state/state.h"

namespace viewer {

class glView : public QOpenGLWidget {
  Q_OBJECT
 public:
  glView(QWidget* parent = nullptr);

  int get_vectors() const;
  int get_surface() const;
  void set_file_name(const QString);
  void set_color(const QString);
  void set_edges(const double);
  void set_vertex(const double);
  void set_shift_x(const double);
  void set_shift_y(const double);
  void set_shift_z(const double);
  void set_rotate_x(const double);
  void set_rotate_y(const double);
  void set_rotate_z(const double);
  void set_scaling(const double);
  void set_shifts_rotates_size(QDoubleSpinBox*, QDoubleSpinBox*,
                               QDoubleSpinBox*, QDoubleSpinBox*,
                               QDoubleSpinBox*, QDoubleSpinBox*,
                               QDoubleSpinBox*);

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void ChooseProjection(const int Type) const;
  void DrawVectors() const;
  void DrawPoints() const;
  void AddColor(const QColor, const QString);
  void AddColorModel(const QColor, const QString);
  void Recalc();
  void TakeGif(const QString);
  void SaveGif();

  QScrollBar* time;
  int point_type = 0;
  int vertex_type = 0;
  int projection_type = 0;

 protected:
  void wheelEvent(QWheelEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;

 private slots:
  void TakePic();

 private:
  void ClearMetrics();
  void ClearData();
  void CreateColor(const ColorPallette& color);

  Difference diff_;
  Originator originator_;
  Caretaker caretaker_;
  Controller controller_;
  QString file_name_ = "";
  int count_vector_ = 0;
  int count_surface_ = 0;
  std::vector<std::tuple<double, double, double>> vectors_;
  std::vector<std::tuple<double, double, double>> current_vectors_;
  std::vector<std::vector<int>> surface_;
  ColorPallette* current_background_;
  ColorPallette* color_vertex_;
  ColorPallette* color_edges_;
  double size_edges_ = 5;
  double size_vertex_ = 0.5;
  QDoubleSpinBox* shift_x_;
  QDoubleSpinBox* shift_y_;
  QDoubleSpinBox* shift_z_;
  QDoubleSpinBox* rotate_x_;
  QDoubleSpinBox* rotate_y_;
  QDoubleSpinBox* rotate_z_;
  QDoubleSpinBox* shift_size_;
  QList<QImage> frames_;
  QTimer* timer_;
  QString file_gif_;
  double speed_ = 120;
  double position_x_ = 0;
  double position_y_ = 0;
  bool shift_ = false;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_
