#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  ReadSettings();
  ui_->open_gl->set_shifts_rotates_size(
      ui_->shift_x, ui_->shift_y, ui_->shift_z, ui_->rotate_x, ui_->rotate_y,
      ui_->rotate_z, ui_->shift_size);
  ui_->open_gl->time = ui_->scroll_timer;
  adapter_ = viewer::Adapter(ui_->open_gl);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::closeEvent(QCloseEvent *event) {
  QMessageBox::StandardButton res_btn = QMessageBox::question(
      this, "A", tr("Save current Settinings?\n"),
      QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
      QMessageBox::Yes);
  if (res_btn != QMessageBox::Yes) {
    if (res_btn == QMessageBox::No) {
      event->accept();
    } else {
      event->ignore();
    }
  } else {
    WriteSettings();
    event->accept();
  }
}

void MainWindow::WriteSettings() const {
  QSettings settings("Cabbage.conf", "AAA");
  int index_vertex = ui_->vertex_settenings->currentIndex();
  int index_edges = ui_->edges_settenings->currentIndex();
  double line_width = ui_->spin_vertex->value();
  double point_width = ui_->spin_edges->value();
  int index_type_projection = ui_->proj_box->currentIndex();
  int index_color_projection = ui_->color_box_proj->currentIndex();
  settings.beginGroup("MainWindow_UI");
  settings.setValue("vertex_settenings/index_vertex", index_vertex);
  settings.setValue("edges_settenings/index_edges", index_edges);
  settings.setValue("spin_vertex/line_width", line_width);
  settings.setValue("spin_edges/point_width", point_width);
  settings.setValue("proj_box/index_type_projection", index_type_projection);
  settings.setValue("color_box_proj/index_color_projection",
                    index_color_projection);
  settings.setValue("file/file_name", ui_->line_file->text());
  settings.endGroup();
}

void MainWindow::ReadSettings() const {
  QSettings settings("Cabbage.conf", "AAA");
  settings.beginGroup("MainWindow_UI");
  ui_->edges_settenings->currentIndexChanged(
      settings.value("edges_settenings/index_edges").toInt());
  ui_->vertex_settenings->currentIndexChanged(
      settings.value("vertex_settenings/index_vertex").toInt());
  ui_->edges_settenings->setCurrentIndex(
      settings.value("edges_settenings/index_edges").toInt());
  ui_->vertex_settenings->setCurrentIndex(
      settings.value("vertex_settenings/index_vertex").toInt());
  ui_->color_box_proj->setCurrentIndex(
      settings.value("color_box_proj/index_color_projection").toInt());
  ui_->proj_box->setCurrentIndex(
      settings.value("proj_box/index_type_projection").toInt());
  ui_->spin_vertex->setValue(
      settings.value("spin_vertex/line_width").toDouble());
  ui_->spin_edges->setValue(
      settings.value("spin_edges/point_width").toDouble());
  ui_->line_file->setText(settings.value("file/file_name").toString());
  ui_->open_gl->set_file_name(settings.value("file/file_name").toString());
  ui_->surface_number->setText(QString::number(ui_->open_gl->get_vectors()));
  ui_->vertex_number->setText(QString::number(ui_->open_gl->get_surface()));
  settings.endGroup();
}

void MainWindow::on_button_file_clicked() {
  OpenFileDialog open_file;
  QString file_name = open_file.GetFileName();
  if (!file_name.isEmpty()) {
    ui_->line_file->setText(file_name);
    ui_->open_gl->set_file_name(file_name);
    ui_->surface_number->setText(QString::number(ui_->open_gl->get_vectors()));
    ui_->vertex_number->setText(QString::number(ui_->open_gl->get_surface()));
  }
}

void MainWindow::on_screen_clicked() {
  QString file = QFileDialog::getSaveFileName(
      this, "Save as...", "name", "BMP (*.bmp);; JPEG (*.jpg *.jpeg)");
  if (!file.isEmpty()) ui_->open_gl->grab().save(file);
}

void MainWindow::on_color_box_proj_currentIndexChanged(int index) {
  ui_->open_gl->set_color(ui_->color_box_proj->currentText());
  ui_->open_gl->repaint();
}

void MainWindow::on_button_gif_clicked() {
  QString file_name = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
                                                   "GIF image (*.gif)");
  if (!file_name.isEmpty()) ui_->open_gl->TakeGif(file_name);
}

void MainWindow::on_spin_vertex_textChanged(const QString &arg1) {
  ui_->open_gl->set_vertex(ui_->spin_vertex->value());
}

void MainWindow::on_spin_edges_textChanged(const QString &arg1) {
  if (ui_->edges_settenings->currentIndex() != 2)
    ui_->open_gl->set_edges(ui_->spin_edges->value());
}

void MainWindow::on_projection_color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) {
    QString name = "Custom " + QString::number(count_custom_color_);
    ++count_custom_color_;
    ui_->open_gl->AddColor(color, name);
    ui_->color_box_proj->addItem(name);
    ui_->color_box_proj->setCurrentIndex(ui_->color_box_proj->count() - 1);
  }
}

void MainWindow::on_vertex_color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) ui_->open_gl->AddColorModel(color, "vertex");
}

void MainWindow::on_edges_color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) ui_->open_gl->AddColorModel(color, "edges");
}

void MainWindow::on_shift_size_editingFinished() {
  ui_->scroll_shift_size->setValue(ui_->shift_size->text().toFloat() * 10);
  ui_->open_gl->set_scaling(ui_->shift_size->value());
}

void MainWindow::on_shift_x_editingFinished() {
  ui_->scroll_shift_x->setValue(ui_->shift_x->text().toFloat() * 100);
  ui_->open_gl->set_shift_x(ui_->shift_x->value());
}

void MainWindow::on_shift_y_editingFinished() {
  ui_->scroll_shift_y->setValue(ui_->shift_y->text().toFloat() * 100);
  ui_->open_gl->set_shift_y(ui_->shift_y->value());
}

void MainWindow::on_shift_z_editingFinished() {
  ui_->scroll_shift_z->setValue(ui_->shift_z->text().toFloat() * 100);
  ui_->open_gl->set_shift_z(ui_->shift_z->value());
}

void MainWindow::on_rotate_x_editingFinished() {
  ui_->scroll_rotate_x->setValue(ui_->rotate_x->text().toFloat());
  ui_->open_gl->set_rotate_x(ui_->rotate_x->value() * (3.14 / 180));
}

void MainWindow::on_rotate_y_editingFinished() {
  ui_->scroll_rotate_y->setValue(ui_->rotate_y->text().toFloat());
  ui_->open_gl->set_rotate_y(ui_->rotate_y->value() * (3.14 / 180));
}

void MainWindow::on_rotate_z_editingFinished() {
  ui_->scroll_rotate_z->setValue(ui_->rotate_z->text().toFloat());
  ui_->open_gl->set_rotate_z(ui_->rotate_z->value() * (3.14 / 180));
}

void MainWindow::on_scroll_shift_size_sliderMoved(int position) {
  adapter_.ShiftSize(position);
}

void MainWindow::on_scroll_shift_x_sliderMoved(int position) {
  adapter_.ShiftX(position);
}

void MainWindow::on_scroll_shift_y_sliderMoved(int position) {
  adapter_.ShiftY(position);
}

void MainWindow::on_scroll_shift_z_sliderMoved(int position) {
  adapter_.ShiftZ(position);
}

void MainWindow::on_scroll_rotate_x_sliderMoved(int position) {
  adapter_.RotateX(position);
}

void MainWindow::on_scroll_rotate_y_sliderMoved(int position) {
  adapter_.RotateY(position);
}

void MainWindow::on_scroll_rotate_z_sliderMoved(int position) {
  adapter_.RotateZ(position);
}

void MainWindow::on_edges_settenings_currentIndexChanged(int index) {
  ui_->open_gl->point_type = index;
  ui_->open_gl->update();
}

void MainWindow::on_vertex_settenings_currentIndexChanged(int index) {
  ui_->open_gl->vertex_type = index;
  ui_->open_gl->update();
}

void MainWindow::on_proj_box_currentIndexChanged(int index) {
  ui_->open_gl->projection_type = index;
  ui_->open_gl->repaint();
}
