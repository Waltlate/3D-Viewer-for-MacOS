#ifndef CPP4_3DVIEWER_V2_0_VIEW_STATE_STATE_H_
#define CPP4_3DVIEWER_V2_0_VIEW_STATE_STATE_H_

#define GL_SILENCE_DEPRECATION

#include <QOpenGLWidget>
#include <iostream>

namespace viewer {

class ProjectionState {
 public:
  ProjectionState() = default;
  virtual ~ProjectionState() = default;
  virtual void Handle() = 0;
};

class CentralState : public ProjectionState {
 public:
  void Handle() override {
    glFrustum(-1, 1, -1, 1, 1, 1000.0);
    glTranslatef(0, 0, -10);
  }
};

class ParallelState : public ProjectionState {
 public:
  void Handle() override { glOrtho(-4.0, 4.0, -4.0, 4.0, -100.5, 100.5); }
};

class Projection {
 private:
  ProjectionState* state_;

 public:
  Projection() : state_(new CentralState()) {}

  void set_state(ProjectionState* new_state) {
    delete state_;
    state_ = new_state;
  }

  void Change() const { state_->Handle(); }
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_VIEW_STATE_STATE_H_
