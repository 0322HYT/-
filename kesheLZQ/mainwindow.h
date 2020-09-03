#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *mouseEvent);



    int gridW;  //棋盘水平方向一个格子的宽度
    int gridH;  //棋盘水平方向一个格子的高度
    int startX; //棋盘起点x坐标
    int startY; //棋盘起点y坐标


    int xPressed;
    int yPressed;
    int numCounts;
    int counts[400][3];
   int checkBoard[19][19];
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
