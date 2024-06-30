#include "glview.h"

#include <QTimer>

#include "../open_file_and_create_gif/gif.h"

#define GL_SILENCE_DEPRECATION

viewer::glView::glView(QWidget* parent) : QOpenGLWidget(parent) {
  CreateColor({"Saphire", 0, 1, 0, 0});
  CreateColor({"White", 255, 255, 255, 0});
  CreateColor({"Black", 0, 0, 0, 0});
  color_vertex_ = new viewer::ColorPallette("Standart", 0.5, 0.5, 0.5, 0);
  color_edges_ = new viewer::ColorPallette("Standart", 1, 0.5, 1, 0);
  current_background_ = new viewer::ColorPallette();
  ClearMetrics();
}

void viewer::glView::CreateColor(const ColorPallette& color) {
  originator_.set_state(color);
  caretaker_.AddMemento(originator_.CreateMemento());
}

void viewer::glView::initializeGL() {}

void viewer::glView::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void viewer::glView::paintGL() {
  if (count_vector_) {
    glViewport(0, 0, 2 * width(), 2 * height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    ChooseProjection(projection_type);
    glMatrixMode(GL_MODELVIEW);
    if (point_type == 0)
      glEnable(GL_POINT_SMOOTH);
    else
      glDisable(GL_POINT_SMOOTH);
    glClearColor(
        current_background_->get_red(), current_background_->get_green(),
        current_background_->get_blue(), current_background_->get_alpha());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawVectors();
    DrawPoints();
  }
}

void viewer::glView::ChooseProjection(const int type) const {
  viewer::Projection projection;
  if (type == 1) {
    projection.Change();
  } else {
    projection.set_state(new viewer::ParallelState());
    projection.Change();
  }
}

void viewer::glView::DrawVectors() const {
  glColor3f(color_vertex_->get_red(), color_vertex_->get_green(),
            color_vertex_->get_blue());
  glLineWidth(size_vertex_);
  glEnable(GL_LINE_STIPPLE);
  if (vertex_type)
    glLineStipple(2, 10);
  else
    glDisable(GL_LINE_STIPPLE);
  int index;
  for (int i = 0; i < count_surface_; ++i) {
    glBegin(GL_LINE_LOOP);
    for (int j = 0; j < surface_[i].size(); ++j) {
      index = surface_[i][j] - 1;
      glVertex3d(std::get<0>(current_vectors_[index]),
                 std::get<1>(current_vectors_[index]),
                 std::get<2>(current_vectors_[index]));
    }
    glEnd();
  }
}

void viewer::glView::DrawPoints() const {
  if (point_type != 2) {
    glColor3f(color_edges_->get_red(), color_edges_->get_green(),
              color_edges_->get_blue());
    glPointSize(size_edges_);
    glBegin(GL_POINTS);
    for (int i = 0; i < count_vector_; ++i) {
      glVertex3d(std::get<0>(current_vectors_[i]),
                 std::get<1>(current_vectors_[i]),
                 std::get<2>(current_vectors_[i]));
    }
    glEnd();
  }
}

void viewer::glView::ClearData() {
  count_vector_ = 0;
  count_surface_ = 0;
  vectors_.clear();
  surface_.clear();
  current_vectors_.clear();
  file_name_ = "";
}

void viewer::glView::set_file_name(const QString file_name) {
  ClearData();
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      obj_data = controller_.ObjRead(file_name);
  if (std::get<0>(obj_data)) {
    count_vector_ = std::get<1>(obj_data);
    count_surface_ = std::get<2>(obj_data);
    vectors_ = std::get<3>(obj_data);
    surface_ = std::get<4>(obj_data);
    current_vectors_ = std::get<3>(obj_data);
    file_name_ = file_name;
    ClearMetrics();
  }
}

void viewer::glView::Recalc() {
  current_vectors_ = controller_.Recalculation(diff_);
  update();
}

void viewer::glView::set_shifts_rotates_size(
    QDoubleSpinBox* shift_x, QDoubleSpinBox* shift_y, QDoubleSpinBox* shift_z,
    QDoubleSpinBox* rotate_x, QDoubleSpinBox* rotate_y,
    QDoubleSpinBox* rotate_z, QDoubleSpinBox* size) {
  shift_x_ = shift_x;
  shift_y_ = shift_y;
  shift_z_ = shift_z;
  rotate_x_ = rotate_x;
  rotate_y_ = rotate_y;
  rotate_z_ = rotate_z;
  shift_size_ = size;
}

void viewer::glView::ClearMetrics() {
  shift_ = 0;
  position_x_ = 0;
  position_y_ = 0;
}

void viewer::glView::set_edges(const double size) {
  size_edges_ = size;
  update();
}

void viewer::glView::set_vertex(const double size) {
  size_vertex_ = size;
  update();
}

void viewer::glView::set_color(const QString color) {
  for (size_t i = 0; i < caretaker_.get_size(); ++i) {
    originator_.RestoreState(caretaker_.get_memento(i), color);
  }
  *current_background_ = originator_.get_state();
}

void viewer::glView::AddColor(const QColor color, const QString color_name) {
  CreateColor({color_name, color.redF(), color.blueF(), color.greenF(),
               color.alphaF()});
}

void viewer::glView::AddColorModel(const QColor color, const QString type) {
  if (type == "vertex")
    color_vertex_->set_pallette(color);
  else if (type == "edges")
    color_edges_->set_pallette(color);
  update();
}

int viewer::glView::get_vectors() const { return count_vector_; }
int viewer::glView::get_surface() const { return count_surface_; }

void viewer::glView::set_scaling(const double size) {
  diff_.set_size(size);
  shift_size_->setValue(size);
  Recalc();
}

void viewer::glView::set_shift_x(const double x) {
  diff_.set_x_move(x);
  shift_x_->setValue(x);
  Recalc();
}

void viewer::glView::set_shift_y(const double y) {
  diff_.set_y_move(y);
  shift_y_->setValue(y);
  Recalc();
}

void viewer::glView::set_shift_z(const double z) {
  diff_.set_z_move(z);
  shift_z_->setValue(z);
  Recalc();
}

void viewer::glView::set_rotate_x(const double x) {
  diff_.set_x_alpha(x);
  rotate_x_->setValue(x * (180 / 3.14));
  Recalc();
}

void viewer::glView::set_rotate_y(const double y) {
  diff_.set_y_alpha(y);
  rotate_y_->setValue(y * (180 / 3.14));
  Recalc();
}

void viewer::glView::set_rotate_z(const double z) {
  diff_.set_z_alpha(z);
  rotate_z_->setValue(z * (180 / 3.14));
  Recalc();
}

void viewer::glView::wheelEvent(QWheelEvent* event) {
  if (event->position().x() > 0 && event->position().y() > 0) {
    diff_.set_size(diff_.get_size() + (double)event->angleDelta().y() / speed_);
    if (diff_.get_size() < 0) diff_.set_size(0);
    set_scaling(diff_.get_size());
  }
}

void viewer::glView::mousePressEvent(QMouseEvent* event) {
  position_x_ = event->scenePosition().x();
  position_y_ = event->scenePosition().y();
}

void viewer::glView::mouseMoveEvent(QMouseEvent* event) {
  if (!shift_) {
    diff_.set_y_alpha(event->position().x() / size().height());
    diff_.set_x_alpha(event->position().y() / size().width());

    rotate_x_->setValue(diff_.get_x_alpha() * (180 / 3.14));
    rotate_y_->setValue(diff_.get_y_alpha() * (180 / 3.14));
  } else {
    diff_.set_x_move(diff_.get_x_move() +
                     (event->scenePosition().x() - position_x_) / speed_ *
                         (diff_.get_size() * 0.5));
    diff_.set_y_move(diff_.get_y_move() +
                     (event->scenePosition().y() - position_y_) / speed_ *
                         (diff_.get_size() * 0.5));
    position_x_ = event->scenePosition().x();
    position_y_ = event->scenePosition().y();
    shift_x_->setValue(diff_.get_x_move());
    shift_y_->setValue(diff_.get_y_move());
  }
  Recalc();
}

void viewer::glView::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Shift) shift_ = 1;
}

void viewer::glView::keyReleaseEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Shift) shift_ = 0;
}

void viewer::glView::TakePic() {
  QImage image = grabFramebuffer();
  time->setValue(time->value() + 1);
  image = image.scaled(640, 480, Qt::IgnoreAspectRatio);
  frames_.push_back(image);
  if (frames_.size() == 30) {
    timer_->stop();
    SaveGif();
  }
}

void viewer::glView::TakeGif(const QString file) {
  time->setValue(0);
  file_gif_ = file;
  timer_ = new QTimer();
  timer_->setInterval(100);
  connect(timer_, SIGNAL(timeout()), this, SLOT(TakePic()));
  timer_->start(100);
}

void viewer::glView::SaveGif() {
  int width = 640;
  int height = 480;
  uint32_t delay = 60 / 10;  // fps
  GifWriter writer;
  GifBegin(&writer, file_gif_.toStdString().c_str(), width, height, delay, 8,
           true);
  for (int i = 0; i < 30; ++i) {
    GifWriteFrame(&writer,
                  frames_[i]
                      .convertToFormat(QImage::Format_Indexed8)
                      .convertToFormat(QImage::Format_RGBA8888)
                      .constBits(),
                  width, height, delay, 8, true);
  }
  GifEnd(&writer);
  frames_.clear();
}
