#include "subwindow.h"

SubWindow::SubWindow(QWidget *parent) : QMainWindow(parent)
{
this->setWindowTitle("小弟");
    this->setMaximumSize(800,800);
    this->setMinimumSize(800,800);

this->numCounts = 0;
    game_flag=0;
    win_flag=0;

    color_flag=1;
}
void SubWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //画棋谱
    painter.setPen(QPen(Qt::red,2));//设置画笔形式
    for(int j=0;j<width;j++)    //划横线
        painter.drawLine(start_x,start_y+j*distance,(height-1)*distance+start_x,j*distance+start_y);
    for(int i=0;i<height;i++)    //画竖线
        painter.drawLine(start_x+i*distance,start_y,i*distance+start_x,(width-1)*distance+start_y);
    //画棋子
    painter.setPen(QPen(Qt::black,2));//设置画笔形式
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            if(chess[i][j]==1)
            {
                painter.setBrush(Qt::black);
                painter.drawEllipse(start_x-radius+i*distance,start_y-radius+j*distance,radius*2,radius*2);
            }
            else if(chess[i][j]==2)
            {
                painter.setBrush(Qt::white);
                painter.drawEllipse(start_x-radius+i*distance,start_y-radius+j*distance,radius*2,radius*2);
            }
        }
    }}
void SubWindow::mouseReleaseEvent(QMouseEvent *event)
    {


        int x=event->x();
        int y=event->y();
        int chess_x=(x-start_x+radius)/distance;
        int chess_y=(y-start_y+radius)/distance;
        if(chess[chess_x][chess_y] != 0)
            return;
        if(color_flag == 1)
        {
            chess[chess_x][chess_y]=1;
            color_flag=2;
            this->numCounts += 1;//棋子数目加一
        }
        else if(color_flag == 2)
        {
            chess[chess_x][chess_y]=2;
            color_flag=1;
            this->numCounts += 1;//棋子数目加一
        }
        checkWin(chess_x,chess_y);
        update();
    }
void SubWindow::checkWin(int x, int y)
{

    int colorCenter = chess[x][y];//中间点的颜色

    if(x>=5&&chess[x-5][y]==colorCenter&&chess[x-4][y]==colorCenter&&chess[x-3][y]==colorCenter&&chess[x-2][y]==colorCenter&&chess[x-1][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=4&&x<=18&&chess[x-4][y]==colorCenter&&chess[x-3][y]==colorCenter&&chess[x-2][y]==colorCenter&&chess[x-1][y]==colorCenter&&chess[x+1][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=3&&x<=17&&chess[x-3][y]==colorCenter&&chess[x-2][y]==colorCenter&&chess[x-1][y]==colorCenter&&chess[x+1][y]==colorCenter&&chess[x+2][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=2&&x<=16&&chess[x-2][y]==colorCenter&&chess[x-1][y]==colorCenter&&chess[x+1][y]==colorCenter&&chess[x+2][y]==colorCenter&&chess[x+3][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=1&&x<=15&&chess[x-1][y]==colorCenter&&chess[x+1][y]==colorCenter&&chess[x+2][y]==colorCenter&&chess[x+3][y]==colorCenter&&chess[x+4][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x<=14&&chess[x+1][y]==colorCenter&&chess[x+2][y]==colorCenter&&chess[x+3][y]==colorCenter&&chess[x+4][y]==colorCenter&&chess[x+5][y]==colorCenter)
    {
        winShow(colorCenter);
    }
    if(y>=5&&chess[x][y-5]==colorCenter&&chess[x][y-4]==colorCenter&&chess[x][y-3]==colorCenter&&chess[x][y-2]==colorCenter&&chess[x][y-1]==colorCenter)
    {
        winShow(colorCenter);
    }
    if(y>=4&&y<=18&&chess[x][y-4]==colorCenter&&chess[x][y-3]==colorCenter&&chess[x][y-2]==colorCenter&&chess[x][y-1]==colorCenter&&chess[x][y+1]==colorCenter)
    {
        winShow(colorCenter);
    }
    if(y>=3&&y<=17&&chess[x][y-3]==colorCenter&&chess[x][y-2]==colorCenter&&chess[x][y-1]==colorCenter&&chess[x][y+1]==colorCenter&&chess[x][y+2]==colorCenter)
    {
        winShow(colorCenter);
    }

    if(y>=2&&y<=16&&chess[x][y-2]==colorCenter&&chess[x][y-1]==colorCenter&&chess[x][y+1]==colorCenter&&chess[x][y+2]==colorCenter&&chess[x][y+3]==colorCenter)
    {
        winShow(colorCenter);
    }
    if(y>=1&&y<=15&&chess[x][y-1]==colorCenter&&chess[x][y+1]==colorCenter&&chess[x][y+2]==colorCenter&&chess[x][y+3]==colorCenter&&chess[x][y+4]==colorCenter)
    {
        winShow(colorCenter);
    }
    if(y<=14&&chess[x][y+1]==colorCenter&&chess[x][y+2]==colorCenter&&chess[x][y+3]==colorCenter&&chess[x][y+4]==colorCenter&&chess[x][y+5]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=5&&y>=5&&chess[x-5][y-5]==colorCenter&&chess[x-4][y-4]==colorCenter&&chess[x-3][y-3]==colorCenter&&chess[x-2][y-2]==colorCenter&&chess[x-1][y-1]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=4&&y>=4&&x<=18&&y<=18&&chess[x-4][y-4]==colorCenter&&chess[x-3][y-3]==colorCenter&&chess[x-2][y-2]==colorCenter&&chess[x-1][y-1]==colorCenter&&chess[x+1][y+1]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=3&&y>=3&&x<=17&&y<=17&&chess[x-3][y-3]==colorCenter&&chess[x-2][y-2]==colorCenter&&chess[x-1][y-1]==colorCenter&&chess[x+1][y+1]==colorCenter&&chess[x+2][y+2]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=2&&y>=2&&x<=16&&y<=16&&chess[x-2][y-2]==colorCenter&&chess[x-1][y-1]==colorCenter&&chess[x+1][y+1]==colorCenter&&chess[x+2][y+2]==colorCenter&&chess[x+3][y+3]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=1&&y>=1&&x<=15&&y<=15&&chess[x-1][y-1]==colorCenter&&chess[x+1][y+1]==colorCenter&&chess[x+2][y+2]==colorCenter&&chess[x+3][y+3]==colorCenter&&chess[x+4][y+4]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x<=14&&y<=14&&chess[x+1][y+1]==colorCenter&&chess[x+2][y+2]==colorCenter&&chess[x+3][y+3]==colorCenter&&chess[x+4][y+4]==colorCenter&&chess[x+5][y+5]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=5&&y<=14&&chess[x-5][y+5]==colorCenter&&chess[x-4][y+4]==colorCenter&&chess[x-3][y+3]==colorCenter&&chess[x-2][y+2]==colorCenter&&chess[x-1][y+1]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=4&&y<=15&&x<=18&&y>=1&&chess[x-4][y+4]==colorCenter&&chess[x-3][y+3]==colorCenter&&chess[x-2][y+2]==colorCenter&&chess[x-1][y+1]==colorCenter&&chess[x+1][y-1]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=3&&y<=16&&x<=17&&y>=2&&chess[x-3][y+3]==colorCenter&&chess[x-2][y+2]==colorCenter&&chess[x-1][y+1]==colorCenter&&chess[x+1][y-1]==colorCenter&&chess[x+2][y-2]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=2&&y<=17&&x<=16&&y>=3&&chess[x-2][y+2]==colorCenter&&chess[x-1][y+1]==colorCenter&&chess[x+1][y-1]==colorCenter&&chess[x+2][y-2]==colorCenter&&chess[x+3][y-3]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x>=1&&y<=18&&x<=15&&y>=4&&chess[x-1][y+1]==colorCenter&&chess[x+1][y-1]==colorCenter&&chess[x+2][y-2]==colorCenter&&chess[x+3][y-3]==colorCenter&&chess[x+4][y-4]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(x<=14&&y>=5&&chess[x+1][y-1]==colorCenter&&chess[x+2][y-2]==colorCenter&&chess[x+3][y-3]==colorCenter&&chess[x+4][y-4]==colorCenter&&chess[x+5][y-5]==colorCenter)
    {
        winShow(colorCenter);
    }
    else if(numCounts==200)
    {
        tie();
    }}

void SubWindow::winShow(int colorCenter)
{
    QString infoShow;
    if(colorCenter == 1)//中心点是黑色
    {
        infoShow = "Black Win!";
    }
    else if(colorCenter == 2)
    {
        infoShow = "White Win!";
    }
    if(QMessageBox::information(NULL,"Game Over",infoShow,"Again","Exit")==1)
    {
        close();
    }
    for(int i=0;i<20;i++)//清空棋盘
    {
        for(int j=0;j<20;j++)
        {
            this->chess[i][j]=0;
        }
    }
    this->color_flag = 1;//下子数目为0，即下一个子从黑子开始
}

void SubWindow::tie()
{
    if(QMessageBox::information(NULL,"Game Over","Tie","Again","Exit")==1)
    {
        close();
    }
    for(int i=0;i<20;i++)//清空棋盘
    {
        for(int j=0;j<20;j++)
        {
            this->chess[i][j]=0;
        }
    }
    this->color_flag = 1;//下子数目为0，即下一个子从黑子开始
}

