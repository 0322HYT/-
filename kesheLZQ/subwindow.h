#ifndef SUBWINDOW_H
#define SUBWINDOW_H
#include <QMainWindow>
#include<QPushButton>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>

class SubWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SubWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *); // 画棋谱
    void mouseReleaseEvent(QMouseEvent *event);
    void checkWin(int x,int y);
    void winShow(int colorCenter);
    void heqi();
    void again();

private:


    const int width=20;        //棋谱列数
    const int height=20;       //棋谱行数
    int chess[20][20]={};
    int distance=40;    //线段距离
    int startX=35;     //起始坐标
    int startY=35;
    int radius=18;  //棋子半径
    int chesscolor;
    int chessnumber;
    QPushButton b4;
    int chessX,chessY;
    int x,y;


};

#endif // SUBWINDOW_H
