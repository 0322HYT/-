#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setWindowTitle("开始界面");
    setMaximumSize(800,450);
    setMinimumSize(800,450);
    b3.setParent(this);
    b3.setText("开始游戏");
    b3.move(300,200);
    b3.resize(200,50);


    //w.show();

    connect(&b3,&QPushButton::released,this,&MainWindow::changeWind);}

void MainWindow::changeWind(){
    w.show();
    hide();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../tu/004.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
