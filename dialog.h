#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QElapsedTimer>
#include <QTime>
extern QTimer *timer;
extern QElapsedTimer etimer;
extern int Timer;

class MainWindow; // Forward declaration
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(MainWindow *mainWindow,int countdownTime,QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void showTime();

private:
    Ui::Dialog *ui;
    MainWindow * mainWindow;
    int countdownTime; // Store countdown time
    QTime countdown; // Store countdown time
};

#endif // DIALOG_H
