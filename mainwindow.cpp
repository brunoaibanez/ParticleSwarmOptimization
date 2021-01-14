#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include <iostream>
#include "mainprogram.h"
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainProgram = MainProgram();
    this->mainProgram.setNumberOfParticles(ui->numberOfParticles->value());

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

    this->started = false;

    this->changeFunctionLabel(":/j1.png");

    QTimer *timer = new QTimer(this);
    this->mytimer = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(on_startButton_clicked()));


}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::showParticles(){

}


void MainWindow::on_startButton_clicked()
{

    this->mainProgram.updatePointsPositions();
    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

    if (!this->started){
        this->mytimer->start(50);
        started = true;
    }
}

void MainWindow::on_stopButton_clicked()
{
    if(started){
        this->mytimer->stop();
        started = false;
    }

}

void MainWindow::on_restartButton_clicked()
{
    if(started){
        this->mytimer->stop();
        started = false;
    }
    this->mainProgram.restartPoints();

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);
}

void MainWindow::on_numberOfParticles_valueChanged(int arg1)
{
    if(started){
        this->mytimer->stop();
        started = false;
    }

    this->mainProgram.setNumberOfParticles(arg1);

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

}

void MainWindow::on_deJongButton1_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::deJongFunction1);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/j1.png");
    }
}

void MainWindow::changeFunctionLabel(std::string path){
    QPixmap mypix (QString::fromStdString(path));
    mypix = mypix.scaled(ui->functionLabel->size(),Qt::KeepAspectRatio);
    ui->functionLabel->setPixmap(mypix);
}

void MainWindow::on_deJongButton2_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::deJongFunction2);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/j2.png");
    }

}

void MainWindow::on_RastriginButton6_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::rastriginFunction6);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/r.png");
    }

}

void MainWindow::on_InerciaBox1_valueChanged(double arg1)
{
    this->mainProgram.setInercia1(arg1);
    this->on_restartButton_clicked();
}

void MainWindow::on_InerciaBox2_valueChanged(double arg1)
{
    this->mainProgram.setInercia2(arg1);
    this->on_restartButton_clicked();
}

void MainWindow::on_InercialWeightBox_valueChanged(double arg1)
{
    this->mainProgram.setInercialWeight(arg1);
    this->on_restartButton_clicked();
}
