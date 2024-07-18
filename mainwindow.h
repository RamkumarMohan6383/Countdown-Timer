#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

class Dialog; // Forward declaration
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Call();

private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    Dialog * dialog;
};
#endif // MAINWINDOW_H
