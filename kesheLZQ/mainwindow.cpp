#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setMaximumSize(800,800);
    this->setMinimumSize(800,800);
    this->xPressed = 0;
    this->yPressed = 0;
    this->numCounts = 0;
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            checkBoard[i][j] = 0;
        }
    }


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    painter.setPen(pen);
    //画线
    for(int i=40;i<800;)
    {
        QPoint pointOne(0,i);
        QPoint pointTwo(800,i);
        painter.drawLine(pointOne,pointTwo);
        i = i + 40;
    }
    for(int i=40;i<800;)
    {
        QPoint pointOne(i,0);
        QPoint pointTwo(i,800);
        painter.drawLine(pointOne,pointTwo);
        i = i + 40;
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
    painter.setBrush(brush);
    painter.drawEllipse(this->counts[i][0]-20,this->counts[i][1]-20,40,40);
  }
  }






















