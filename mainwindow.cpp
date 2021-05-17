#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include <iostream>
#include "mainprogram.h"
#include <QTimer>
#include <unistd.h>
#include <thread>         // std::thread

int MainWindow::numberMaxOfIterations = ModelDefaultConstants::defaultNumMaxIterations;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainProgram = MainProgram();
    this->mainProgram.setNumberOfParticles(ui->numberOfParticles->value());

    numberIterations = 0;

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

    this->started = false;

    this->changeFunctionLabel(":/j1.png");

    QTimer *timer = new QTimer(this);
    this->mytimer = timer;
    //connect(timer, SIGNAL(timeout()), this, SLOT(show_particles()));


}

MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::analysis_particles(){

    std::cout << "aqui" << std::endl;
    // Create an empty vector
    std::vector<std::string> vect = std::vector<std::string> ();

    vect.push_back(StringConstants::deJongFunction1);
    vect.push_back(StringConstants::deJongFunction2);
    vect.push_back(StringConstants::griewankFunction);
    vect.push_back(StringConstants::rastriginFunction6);
    vect.push_back(StringConstants::schafferFunction);
    vect.push_back(StringConstants::rosenbrockFunction);

    std::cout << "aqui" << std::endl;
    for(int i = 0; i < vect.size(); i++){
         std::cout << "aca" << std::endl;
        this->mainProgram.setOptimizationFunction(vect.at(i));
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();

         usleep(1000000);

        for (int j = 0; j < 11; j++){
             std::cout << "oco" << std::endl;
            if (j==0){
                this->on_numberOfParticles_valueChanged(1);
            }
            else{
                this->on_numberOfParticles_valueChanged(j*10);
            }

            this->on_startButton_clicked();

            while(numberIterations != MainWindow::numberMaxOfIterations){
                usleep(10000);
                this->on_startButton_clicked();
            }
            this->on_restartButton_clicked();
            numberIterations = 0;


        }
    }
}

void MainWindow::analysis_max_velocity(){

    std::cout << "aqui" << std::endl;
    // Create an empty vector
    std::vector<std::string> vect = std::vector<std::string> ();

    vect.push_back(StringConstants::deJongFunction1);
    vect.push_back(StringConstants::deJongFunction2);
    vect.push_back(StringConstants::griewankFunction);
    vect.push_back(StringConstants::rastriginFunction6);
    vect.push_back(StringConstants::schafferFunction);
    vect.push_back(StringConstants::rosenbrockFunction);

    std::cout << "aqui" << std::endl;
    for(int i = 0; i < vect.size(); i++){
         std::cout << "aca" << std::endl;
        this->mainProgram.setOptimizationFunction(vect.at(i));
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();

         usleep(10000);

        for (int j = 0; j < 5; j++){
             std::cout << "oco" << std::endl;
            if (j==0){
                this->on_MaxVelocity_valueChanged(1);
            }
            else{
                this->on_MaxVelocity_valueChanged(j*10);
            }
            this->on_numberOfParticles_valueChanged(100);

            this->on_startButton_clicked();

            while(numberIterations != MainWindow::numberMaxOfIterations){
                usleep(10000);
                this->on_startButton_clicked();
            }
            this->on_restartButton_clicked();
            numberIterations = 0;


        }
    }
}

void MainWindow::analysis_glob_inertia(){

    std::cout << "aqui" << std::endl;
    // Create an empty vector
    std::vector<std::string> vect = std::vector<std::string> ();

    vect.push_back(StringConstants::deJongFunction1);
    vect.push_back(StringConstants::deJongFunction2);
    vect.push_back(StringConstants::griewankFunction);
    vect.push_back(StringConstants::rastriginFunction6);
    vect.push_back(StringConstants::schafferFunction);
    vect.push_back(StringConstants::rosenbrockFunction);

    std::cout << "aqui" << std::endl;
    for(int i = 0; i < vect.size(); i++){
         std::cout << "aca" << std::endl;
        this->mainProgram.setOptimizationFunction(vect.at(i));
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();

         usleep(10000);

        for (int j = 0; j < 5; j++){
             std::cout << "oco" << std::endl;
            if (j==0){
                this->on_InerciaBox2_valueChanged(0);
            }
            else{
                this->on_InerciaBox2_valueChanged(j*0.25);
            }

            this->on_startButton_clicked();

            while(numberIterations != MainWindow::numberMaxOfIterations){
                usleep(10000);
                this->on_startButton_clicked();
            }
            this->on_restartButton_clicked();
            numberIterations = 0;
        }
    }
}


void MainWindow::analysis_ind_intertia(){

    std::cout << "aqui" << std::endl;
    // Create an empty vector
    std::vector<std::string> vect = std::vector<std::string> ();

    vect.push_back(StringConstants::deJongFunction1);
    vect.push_back(StringConstants::deJongFunction2);
    vect.push_back(StringConstants::griewankFunction);
    vect.push_back(StringConstants::rastriginFunction6);
    vect.push_back(StringConstants::schafferFunction);
    vect.push_back(StringConstants::rosenbrockFunction);

    std::cout << "aqui" << std::endl;
    for(int i = 0; i < vect.size(); i++){
         std::cout << "aca" << std::endl;
        this->mainProgram.setOptimizationFunction(vect.at(i));
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();

         usleep(10000);

        for (int j = 0; j < 5; j++){
             std::cout << "oco" << std::endl;
            if (j==0){
                this->on_InerciaBox1_valueChanged(0);
            }
            else{
                this->on_InerciaBox1_valueChanged(j*0.25);
            }

            this->on_startButton_clicked();

            while(numberIterations != MainWindow::numberMaxOfIterations){
                usleep(10000);
                this->on_startButton_clicked();
            }
            this->on_restartButton_clicked();
            numberIterations = 0;
        }
    }
}


void MainWindow::showParticles(){

}


void MainWindow::on_startButton_clicked()
{

    this->mainProgram.updatePointsPositions();
    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

    if (numberIterations % 50 == 0 ){
        std::cout << numberIterations << std::endl;
    }

    if (!this->started){
        this->mytimer->start(50);
        started = true;
    }

    this->mainProgram.analysisAlgorithm(numberIterations);
    numberIterations++;
    if(numberIterations == MainWindow::numberMaxOfIterations){
        this->on_stopButton_clicked();
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
    numberIterations = 0;
    this->mainProgram.clearAnalysisVectors();
    this->mainProgram.restartPoints();

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);

}

void MainWindow::on_numberOfParticles_valueChanged(int arg1)
{
    if(started){
        this->mytimer->stop();
        started = false;
        numberIterations = 0;
    }

    this->mainProgram.setNumberOfParticles(arg1);

    QPixmap q = this->mainProgram.refreshWindow();
    ui->labelGrid->setPixmap(q);
    this->on_restartButton_clicked();

}

void MainWindow::on_MaxVelocity_valueChanged(double arg1)
{
    if(started){
        this->mytimer->stop();
        started = false;
    }

    Particle::maxVelocity = arg1;

    this->on_restartButton_clicked();
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


void MainWindow::on_RosenbrockButton_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::rosenbrockFunction);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/r.png");
    }
}

void MainWindow::on_SchafferButton_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::schafferFunction);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/r.png");
    }
}

void MainWindow::on_GriewankButton_toggled(bool checked)
{
    if (checked){
        this->mainProgram.setOptimizationFunction(StringConstants::griewankFunction);
        this->mainProgram.setPixmap();
        this->on_restartButton_clicked();
        this->changeFunctionLabel(":/j2.png");
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

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    this->numberMaxOfIterations = arg1;
    MainProgram::numberMaxOfIterations = arg1;
    this->on_restartButton_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    this->analysis_ind_intertia();
}
