#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QElapsedTimer>

extern QTimer *timer;
extern QElapsedTimer etimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void showTime();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
