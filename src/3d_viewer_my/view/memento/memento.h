#ifndef CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_MEMENTO_H_
#define CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_MEMENTO_H_

#include <stdio.h>

#include <QMainWindow>
#include <QSettings>

#include "../view/color.h"

namespace viewer {

class Originator {
 public:
  void set_state(const ColorPallette& color) { color_ = color; }

  ColorPallette get_state() const { return color_; }

  class Memento {
   private:
    ColorPallette color_;

   public:
    Memento(const ColorPallette& color) : color_(color) {}

    ColorPallette get_saved_state() const { return color_; }
  };

  Memento CreateMemento() const { return Memento(color_); }

  void RestoreState(const Memento& memento, const QString color) {
    if (memento.get_saved_state().get_name() == color) {
      color_ = memento.get_saved_state();
    }
  }

 private:
  ColorPallette color_;
};

// Caretaker: Manages the Memento objects.
class Caretaker {
 public:
  void AddMemento(const Originator::Memento& memento) {
    mementos_.push_back(memento);
  }

  Originator::Memento get_memento(int index) const {
    if (index >= 0 && index < mementos_.size()) {
      return mementos_[index];
    }
    throw std::out_of_range("Invalid Memento index");
  }
  size_t get_size() const { return mementos_.size(); };

 private:
  std::vector<Originator::Memento> mementos_;
};

}  // namespace viewer

#endif  // CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_MEMENTO_H_
