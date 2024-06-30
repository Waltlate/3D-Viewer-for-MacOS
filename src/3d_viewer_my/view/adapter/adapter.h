#ifndef CPP4_3DVIEWER_V2_0_VIEW_ADAPTER_ADAPTER_H_
#define CPP4_3DVIEWER_V2_0_VIEW_ADAPTER_ADAPTER_H_

#include "glview.h"

namespace viewer {

class Adapter {
 public:
  Adapter() : model_(nullptr) {}
  Adapter(glView *obj) { model_ = obj; }

  void ShiftSize(const int shift) const {
    model_->set_scaling((double)shift / 10);
  }
  void RotateX(const int shift) const {
    model_->set_rotate_x((double)shift / 100);
  }
  void RotateY(const int shift) const {
    model_->set_rotate_y((double)shift / 100);
  }
  void RotateZ(const int shift) const {
    model_->set_rotate_z((double)shift / 100);
  }
  void ShiftX(const int shift) const { model_->set_shift_x((double)shift / 100); }
  void ShiftY(const int shift) const { model_->set_shift_y((double)shift / 100); }
  void ShiftZ(const int shift) const { model_->set_shift_z((double)shift / 100); }

 private:
  glView *model_;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_VIEW_ADAPTER_ADAPTER_H_
