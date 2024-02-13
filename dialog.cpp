#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include<QElapsedTimer>
int Timer=0;
QElapsedTimer etimer;
QTimer* timer = new QTimer();

Dialog::Dialog(MainWindow *mainWindow,int countdownTime, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    mainWindow(mainWindow), // Initialize mainWindow pointer to nullptr
    countdownTime(countdownTime), // Initialize countdown time
    countdown(0, countdownTime, 0, 0) // Initialize countdown with the new value of time
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->setTimerType(Qt::PreciseTimer); // Ensure precise timing
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showTime()
{
    auto elapsed = etimer.elapsed();
    auto c = countdown.addSecs(-elapsed / 1000); // Convert elapsed milliseconds to seconds
    QString timestr = c.toString("mm:ss");
    if (timestr == "00:00")
    {
        timer->stop();
        hide();
        mainWindow->Call();
        ui->lcdNumber->display(timestr);
    }
    else
    {
        ui->lcdNumber->display(timestr);
    }

}
