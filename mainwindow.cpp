#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QTime>
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dialog (nullptr) // Initialize dialog pointer to nullptr
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int time = ui->lineEdit->text().toInt(); // Use lowercase for variable names
       dialog = new Dialog(this,time, this); // Pass countdown time to Dialog constructor
       dialog->show();
       etimer.start();
       timer->start(1000);
}

void MainWindow::Call()
{
    qDebug()<<"Timer End...";
}
