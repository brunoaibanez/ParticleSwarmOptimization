#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "mainprogram.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainProgram = MainProgram();
    this->notstarted = true;
    this->mainProgram.setNumberOfParticles(ui->numberOfParticles->value());

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::showParticles(){

}


void MainWindow::on_startButton_clicked()
{

    int w = ui->labelGrid->width();
    int h = ui->labelGrid->height();
    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

    if (notstarted){
        QTimer *timer = new QTimer(this);
        this->mytimer = timer;

        connect(timer, SIGNAL(timeout()), this, SLOT(on_startButton_clicked()));
        timer->start(1000);
        notstarted = false;
    }
}

void MainWindow::on_stopButton_clicked()
{
    this->mytimer->stop();
    notstarted = true;
}

void MainWindow::on_restartButton_clicked()
{
    this->mytimer->stop();
    notstarted = true;
    this->mainProgram.restartPoints();

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);
}

void MainWindow::on_numberOfParticles_valueChanged(int arg1)
{
    this->mytimer->stop();
    notstarted = true;
    this->mainProgram.setNumberOfParticles(arg1);

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

}
