#include "subwindow.h"
#include<QPushButton>
SubWindow::SubWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("游戏界面");
    setMaximumSize(1000,830);
    setMinimumSize(1000,830);

    chessnumber = 0;
    chesscolor=1;
    b4.setParent(this);
    b4.setText("重新开始");
    b4.move(840,100);
    b4.resize(150,50);
    connect(&b4,&QPushButton::released,this,&SubWindow::again);


}


void SubWindow::again(){
    for(int i=0;i<20;i++)//清空棋盘
    {
        for(int j=0;j<20;j++)
        {
            this->chess[i][j]=0;
        }
    }
    chesscolor = 1;//下子数目为0，即下一个子从黑子开始
    update();
}
void SubWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //画棋谱
    p.drawPixmap(0,0,830,830,QPixmap("../tu/007.jfif"));
    p.setPen(QPen(Qt::black,2));//设置画笔形式
    for(int j=0;j<width;j++)
        p.drawLine(startX,startY+j*distance,(height-1)*distance+startX,j*distance+startY);
    for(int i=0;i<height;i++)
        p.drawLine(startX+i*distance,startY,i*distance+startX,(width-1)*distance+startY);
    //画棋子
    p.setPen(QPen(Qt::black,2));//设置画笔形式
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            if(chess[i][j]==1)
            {
                p.setBrush(Qt::black);
                p.drawEllipse(startX-radius+i*distance,startY-radius+j*distance,radius*2,radius*2);
            }
            else if(chess[i][j]==2)
            {
                p.setBrush(Qt::white);
                p.drawEllipse(startX-radius+i*distance,startY-radius+j*distance,radius*2,radius*2);
            }
        }
    }}
void SubWindow::mouseReleaseEvent(QMouseEvent *event)
    {


        x=event->x();
        y=event->y();
        chessX=(x-startX+radius)/distance;
        chessY=(y-startY+radius)/distance;

        if(chess[chessX][chessY] != 0)
            return;
        if(chesscolor == 1)
        {
            chess[chessX][chessY]=1;
            chesscolor=2;
            chessnumber += 1;//棋子数目加一
        }
        else if(chesscolor == 2)
        {
            chess[chessX][chessY]=2;
            chesscolor=1;
            chessnumber += 1;//棋子数目加一
        }

        checkWin(chessX,chessY);
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
    else if(chessnumber==400)
    {
        heqi();
    }}

void SubWindow::winShow(int colorCenter)
{
    QString infoShow;
    if(colorCenter == 1)//中心点是黑色
    {
        infoShow = "黑棋胜利!";
    }
    else if(colorCenter == 2)
    {
        infoShow = "白棋胜利!";
    }
    if(QMessageBox::information(NULL,"游戏结束",infoShow,"再来一次","退出")==1)
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
    chesscolor = 1;//下一个子从黑子开始
}

void SubWindow::heqi()
{
    if(QMessageBox::information(NULL,"游戏结束","和棋","再来一次","退出")==1)
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
   chesscolor = 1;//下一个子从黑子开始
}

