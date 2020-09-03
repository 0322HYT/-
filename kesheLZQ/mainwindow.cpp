#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setMaximumSize(840,840);
    this->setMinimumSize(840,840);
    this->xPressed = 0;
    this->yPressed = 0;
    this->numCounts = 0;
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            checkBoard[i][j] = 0;
        }
    }//初始化


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    gridW = width()/21;  //窗口宽度分21份
    gridH = height()/21; //窗口高度分21份

    //棋盘起点坐标
    startX = gridW;
    startY = gridH;

    QPainter p(this); //创建画家，指定窗口为绘图设备

   p.setPen(QPen(Qt::black,2));//设置画笔形式


    //取中间20份画棋盘
    for(int i = 0; i <= 19; i++)
    {
        //横线
        p.drawLine(startX, startY+i*gridH, startX+19*gridW, startY+i*gridH);

        //竖线
        p.drawLine(startX+i*gridW, startY, startX+i*gridW, startY+19*gridH);
    }
   QBrush brush;
    brush.setStyle(Qt::SolidPattern);
   for(int i=0;i<this->numCounts;i++)
   {
     if(i%2 == 0)
     {
         brush.setColor(Qt::black);
     }
     else
     {
         brush.setColor(Qt::white);
     }
     p.setBrush(brush);
     p.drawEllipse(this->counts[i][0]-20,this->counts[i][1]-20,20,20);
   }
  }
void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
{
    int x = int(float(mouseEvent->x()));
    int y = int(float(mouseEvent->y()));

    //按下的位置在棋盘内
    if(x >= startX && x <= startX+19*gridW
       && y >= startY && y <= startX+19*gridH)//当前按键位置在棋盘内并且当前位置没有棋子
    {
        this->numCounts += 1;//棋子数目加一
        if(this->numCounts%2 != 0)//棋局矩阵构造
        {
            this->checkBoard[y/40-1][x/40-1] = 1; //1表示黑色
        }
        else
        {
            this->checkBoard[y/40-1][x/40-1] = -1;//-1表示白色
        }
        this->counts[this->numCounts-1][0] = x;
        this->counts[this->numCounts-1][1] = y;
        this->counts[this->numCounts-1][2] = this->numCounts%2;

        this->update();      //用于绘图
    }

}






















