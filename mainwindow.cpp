#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>


using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::text = ui->textEdit;
    MainWindow::save = ui->actionSave_2;
    MainWindow::open = ui->actionOpen_File;

    connect(MainWindow::save, &QAction::triggered, this, &MainWindow::SaveFile);
    connect(MainWindow::open, &QAction::triggered, this, &MainWindow::OpenFile);
}

void MainWindow::SaveFile() {
    ofstream fileToSave ("test.txt");
    fileToSave << MainWindow::text->toPlainText().toStdString();
    fileToSave.close();
}

void MainWindow::OpenFile() {
    ifstream fileToOpen ("test.txt");
    string content;
    char ch;
    while (fileToOpen.get(ch)) {
        content += ch;
    }
    MainWindow::text->setText(QString::fromLocal8Bit(content.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
