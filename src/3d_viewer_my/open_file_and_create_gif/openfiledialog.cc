#include "openfiledialog.h"

QString OpenFileDialog::GetFileName() {
  QString path = QDir::currentPath() + "/../../";
  QString filename =
      QFileDialog::getOpenFileName(nullptr, QObject::tr("Open File"), path,
                                   QObject::tr("Document files (*.obj)"));

  return filename;
}
