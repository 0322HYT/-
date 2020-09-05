#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b3.setParent(this);
    b3.setText("开始游戏");
    b3.move(50,50);
    b3.resize(200,50);


    //w.show();

    connect(&b3,&QPushButton::released,this,&MainWindow::changeWind);}

void MainWindow::changeWind(){
    w.show();
    hide();
}



MainWindow::~MainWindow()
{
    delete ui;
}
