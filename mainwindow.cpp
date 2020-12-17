#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "mainprogram.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainProgram = MainProgram();

}

MainWindow::~MainWindow()
{


    delete ui;
}


/*
void MainWindow::setMainProgram(MainProgram * m){
    std::cout << m->particles.at(0)->qpoint.x() << std::endl;
    this->mainProgram = m;
    std::cout << this->mainProgram->particles.at(0)->qpoint.x() << std::endl;
}
*/
void MainWindow::showParticles(){

}

void MainWindow::on_pushButton_clicked()
{

    int w = ui->labelGrid->width();
    int h = ui->labelGrid->height();
    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q.scaled(w,h,Qt::KeepAspectRatio));

}

void MainWindow::on_pushButton_2_pressed()
{

}
