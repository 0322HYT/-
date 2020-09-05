#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include"subwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void changeWind();

private:
    Ui::MainWindow *ui;
    QPushButton b3;
    SubWindow w;


};

#endif // MAINWINDOW_H
