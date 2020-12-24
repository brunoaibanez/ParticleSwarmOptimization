#include "mainprogram.h"
#include "constants.h"
#include <iostream>


MainProgram::MainProgram()
{

    this->setPixmap();


}

void MainProgram::setNumberOfParticles(int numberOfParticles){

    this->particles.clear();
    this->particlesFirstIteration.clear();
    Particle::clearGlobalVariables();
    for (int i = 0; i<numberOfParticles; i++){
        //TODO put it random or something bro
        Particle* p = new Particle(i*10,i*20, 2*i+1, 3*i+1);
        Particle* pcopy = new Particle(i*10,i*20, 2*i+1, 3*i+1);

        this->particles.push_back(p);
        this->particlesFirstIteration.push_back(pcopy);
    }

    std::cout << "x on set: " << this->particlesFirstIteration.at(0)->qpoint.x() << std::endl;
    std::cout << "y on set: " << this->particlesFirstIteration.at(0)->qpoint.y() << std::endl;
}

void MainProgram::updatePointsPositions(){

    for (int i = 0; i < this->particles.size(); i++)
    {
        Particle * p = this->particles.at(i);
        p->updatePosition();
    }

}

QPixmap MainProgram::refreshWindow(){
    QPixmap q = *this->qpixMap;

    for (int i = 0; i < this->particles.size(); i++) // access by reference to avoid copying
    {
        Particle * p = this->particles.at(i);
        this->paintPoint(&q,p);
    }

    return q;
}


void MainProgram::paintPoint(QPixmap * q, Particle * particle){
    QPainter *painter = new QPainter(q);
    QPen linepen(Qt::red);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(5);
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(linepen);
    QPoint qpaintpoint = particle->getPrintPoint();
    painter->drawPoint(qpaintpoint);
    QString qs = "("+ QString::number(particle->qvelocity.x()) + " , " + QString::number(particle->qvelocity.y()) + ")";
    QPoint qpos = qpaintpoint + QPoint(5,5);
    painter->drawText(qpos,qs);
    delete painter;
}


void MainProgram::restartPoints(){
    this->particles.clear();
    Particle::clearGlobalVariables();
    for (int i = 0; i < this->particlesFirstIteration.size(); i++){
        int posx = this->particlesFirstIteration[i]->qpoint.x();
        int posy = this->particlesFirstIteration[i]->qpoint.y();
        int vx = this->particlesFirstIteration[i]->qvelocity.x();
        int vy = this->particlesFirstIteration[i]->qvelocity.y();
        Particle* pcopy = new Particle(posx, posy, vx, vy);

        this->particles.push_back(pcopy);
    }
}

void MainProgram::setOptimizationFunction(std::string function){
    Particle::setOptimizationFunction(function);
}

void MainProgram::setPixmap(){
    QPixmap* mappingPixmap = new QPixmap(WindowConstants::WIDTH, WindowConstants::HEIGHT);
    std::vector<std::vector<float>> mappingMatrix;
    float maxValue = 0;

    for (int i = 0; i < WindowConstants::WIDTH; i++){
        std::vector<float> aux;
        mappingMatrix.push_back(aux);
        for (int j = 0; j < WindowConstants::HEIGHT; j++){
            int posx = i - WindowConstants::WIDTH/2;
            int posy = j - WindowConstants::HEIGHT/2;
            int vx = 0;
            int vy = 0;
            Particle paux = Particle(posx, posy, vx, vy);

            float value = paux.getOptimizationValue();
            mappingMatrix.at(i).push_back(value);

            if (value > maxValue){
                maxValue = value;
            }
        }
    }

    QPainter *painter = new QPainter(mappingPixmap);

    for (int i = 0; i < WindowConstants::WIDTH; i++){
        for (int j = 0; j < WindowConstants::HEIGHT; j++){
            float valueNormalized = mappingMatrix.at(i).at(j) / maxValue;
            int valuePixel = int(valueNormalized * 255);

            QPen linepen(QColor(valuePixel,valuePixel,valuePixel,200));
            linepen.setCapStyle(Qt::RoundCap);
            linepen.setWidth(3);
            painter->setPen(linepen);
            QPoint qpaintpoint = QPoint(i,j);
            painter->drawPoint(qpaintpoint);

        }
    }


    this->qpixMap = mappingPixmap;

    delete painter;

}
