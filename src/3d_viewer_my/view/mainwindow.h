#ifndef CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_

#include <QtWidgets/QFileDialog.h>

#include <QCloseEvent>
#include <QColorDialog>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QOpenGLWidget>>
#include <QSettings>

#include "../open_file_and_create_gif/openfiledialog.h"
#include "./ui_mainwindow.h"
#include "adapter/adapter.h"
#include "glview.h"

QT_BEGIN_NAMESPACE
namespace viewer {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_button_file_clicked();
  void on_screen_clicked();
  void on_color_box_proj_currentIndexChanged(int index);
  void on_button_gif_clicked();
  void on_spin_vertex_textChanged(const QString &arg1);
  void on_spin_edges_textChanged(const QString &arg1);
  void on_projection_color_clicked();
  void on_vertex_color_clicked();
  void on_edges_color_clicked();
  void on_shift_x_editingFinished();
  void on_shift_z_editingFinished();
  void on_shift_y_editingFinished();
  void on_rotate_x_editingFinished();
  void on_rotate_y_editingFinished();
  void on_rotate_z_editingFinished();
  void on_scroll_shift_z_sliderMoved(int position);
  void on_scroll_shift_y_sliderMoved(int position);
  void on_scroll_shift_x_sliderMoved(int position);
  void on_scroll_rotate_x_sliderMoved(int position);
  void on_scroll_rotate_y_sliderMoved(int position);
  void on_scroll_rotate_z_sliderMoved(int position);
  void on_scroll_shift_size_sliderMoved(int position);
  void on_shift_size_editingFinished();
  void on_edges_settenings_currentIndexChanged(int index);
  void on_vertex_settenings_currentIndexChanged(int index);
  void on_proj_box_currentIndexChanged(int index);
  void closeEvent(QCloseEvent *event);

private:
  void WriteSettings() const;
  void ReadSettings() const;
  Ui::MainWindow *ui_;
  viewer::Adapter adapter_;
  int count_custom_color_ = 1;
};
#endif  // CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
