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

    void tie();

private:
    int game_flag;

    const int width=20;        //棋谱宽度
    const int height=20;       //棋谱高度
    int chess[20][20]={};
    int distance=40;    //线段距离
    int start_x=20;     //起始坐标
    int start_y=20;

    int radius=18;  //棋子半径
    int color_flag;
    int win_flag;
    int source[15][15]={};
int numCounts;


};

#endif // SUBWINDOW_H
