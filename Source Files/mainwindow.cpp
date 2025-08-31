#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(600,800);
    AirDisplay* display = new AirDisplay(this);
    setCentralWidget(display);
}

MainWindow::~MainWindow() {    
}
