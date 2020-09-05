#ifndef SUBWINDOW_H
#define SUBWINDOW_H
#include <QMainWindow>
#include<QPushButton>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
class SubWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SubWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *); // 画棋谱
        // 实际落子
    void mouseReleaseEvent(QMouseEvent *event);
    void checkWin(int x,int y);
    void winShow(int colorCenter);
    void heqi();

private:


    const int width=20;        //棋谱列数
    const int height=20;       //棋谱行数
    int chess[20][20]={};
    int distance=40;    //线段距离
    int startX=20;     //起始坐标
    int startY=20;
    int radius=18;  //棋子半径
    int chesscolor;
    int chessnumber;


};

#endif // SUBWINDOW_H
