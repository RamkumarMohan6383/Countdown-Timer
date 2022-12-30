#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include<QElapsedTimer>

QElapsedTimer etimer;
QTimer* timer = new QTimer();
auto countdown= QTime(0,0,30);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    auto elapsed =etimer.elapsed();
    auto c=countdown.addMSecs(-elapsed);
    QString timestr = c.toString("mm:ss");
    ui->lcdNumber->display(timestr);
}

void MainWindow::on_pushButton_clicked()
{
    etimer.start();
    timer->start(1000);
}
