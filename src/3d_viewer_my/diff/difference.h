#ifndef CPP4_3DVIEWER_V2_0_MODEL_DIFF_H_
#define CPP4_3DVIEWER_V2_0_MODEL_DIFF_H_

namespace viewer {

class Difference {
 public:
  Difference() {
    x_move_ = 0;
    y_move_ = 0;
    z_move_ = 0;
    x_alpha_ = 0;
    y_alpha_ = 0;
    z_alpha_ = 0;
    size_ = 1;
  }

  Difference(double x_move, double y_move, double z_move, double size,
             double x_alpha, double y_alpha, double z_alpha) {
    x_move_ = x_move;
    y_move_ = y_move;
    z_move_ = z_move;
    x_alpha_ = x_alpha;
    y_alpha_ = y_alpha;
    z_alpha_ = z_alpha;
    size_ = size;
  }

  void set_x_move(const double x_move) { x_move_ = x_move; }
  void set_y_move(const double y_move) { y_move_ = y_move; }
  void set_z_move(const double z_move) { z_move_ = z_move; }
  void set_x_alpha(const double x_alpha) { x_alpha_ = x_alpha; }
  void set_y_alpha(const double y_alpha) { y_alpha_ = y_alpha; }
  void set_z_alpha(const double z_alpha) { z_alpha_ = z_alpha; }
  void set_size(const double size) { size_ = size; }
  double get_x_move() const { return x_move_; }
  double get_y_move() const { return y_move_; }
  double get_z_move() const { return z_move_; }
  double get_x_alpha() const { return x_alpha_; }
  double get_y_alpha() const { return y_alpha_; }
  double get_z_alpha() const { return z_alpha_; }
  double get_size() const { return size_; }

 private:
  double x_move_ = 0;
  double y_move_ = 0;
  double z_move_ = 0;
  double x_alpha_ = 0;
  double y_alpha_ = 0;
  double z_alpha_ = 0;
  double size_ = 1;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_MODEL_DIFF_H_
