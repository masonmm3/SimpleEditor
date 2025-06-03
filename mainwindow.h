#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QString>
#include <QListView>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
public slots:
  void SaveFile();
  void OpenFile();
  void LoadFolder();
  void CloseFile();

private:
  Ui::MainWindow *ui;
  QTextEdit *text;
  QAction *save;
  QAction *open;
  QAction *close;
  QAction *folder;
  string *openedFile = nullptr;
};
#endif // MAINWINDOW_H
