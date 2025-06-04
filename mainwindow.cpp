#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <qcontainerfwd.h>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <string>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    MainWindow::text = ui->textEdit;
    MainWindow::save = ui->actionSave_2;
    MainWindow::open = ui->actionOpen_File;
    MainWindow::folder = ui->actionload_folder;
    MainWindow::close = ui->actionClose;

    connect(MainWindow::save, &QAction::triggered, this, &MainWindow::SaveFile);
    connect(MainWindow::open, &QAction::triggered, this, &MainWindow::OpenFile);
    connect(MainWindow::close, &QAction::triggered, this, &MainWindow::CloseFile);
}

void MainWindow::SaveFile() {
    QFileDialog dialog(this);
    QString DIR;
    string fileName;
    if (MainWindow::openedFile == nullptr) {
        QString saveFile = QFileDialog::getSaveFileName(this, tr("Open File"), DIR, tr("System Files(*.txt)"));
        fileName = saveFile.toStdString();
    } else {
        fileName = *MainWindow::openedFile;
    }



    ofstream fileToSave(fileName);
    fileToSave << MainWindow::text->toPlainText().toStdString();
    fileToSave.close();
    if (MainWindow::openedFile != nullptr) {
        delete MainWindow::openedFile;
        MainWindow::openedFile = nullptr;
    }

    MainWindow::openedFile = new string(fileName);
}

void MainWindow::CloseFile() {
    if (MainWindow::openedFile != nullptr) {
        MainWindow::text->setText("");
        delete MainWindow::openedFile;
        MainWindow::openedFile = nullptr;
    }
}

void MainWindow::OpenFile() {
    QFileDialog dialog(this);
    QString DIR;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), DIR, tr("System Files(*.txt)"));
    if (fileName != nullptr) {
        ifstream fileToOpen(fileName.toStdString());
        string content;
        char ch;
        while (fileToOpen.get(ch)) {
            content += ch;
        }
        MainWindow::text->setText(QString::fromLocal8Bit(content.c_str()));
        MainWindow::openedFile = new string(fileName.toStdString());
    }
}

void MainWindow::LoadFolder() {
}



MainWindow::~MainWindow() {
    delete ui;
}
