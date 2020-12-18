#include "mainprogram.h"
#include "constants.h"
#include <iostream>


MainProgram::MainProgram()
{


}

void MainProgram::setNumberOfParticles(int numberOfParticles){

    this->particles.clear();
    this->particlesFirstIteration.clear();
    for (int i = 0; i<numberOfParticles; i++){
        Particle* p = new Particle(i*100,i*100+50, 2*i+1, 3*i+1);
        Particle* pcopy = new Particle(i*100,i*100+50, 2*i+1, 3*i+1);

        this->particles.push_back(p);
        this->particlesFirstIteration.push_back(pcopy);
    }
}

void MainProgram::updatePointsPositions(){

    for (int i = 0; i < this->particles.size(); i++)
    {
        Particle * p = this->particles.at(i);
        p->updatePosition();
    }

}

QPixmap MainProgram::refreshWindow(){
    QPixmap q = QPixmap(WindowConstants::WIDTH, WindowConstants::HEIGHT);
    q.fill(Qt::white);

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
    painter->drawPoint(particle->qpoint);
    QString qs = "("+ QString::number(particle->qvelocity.x()) + " , " + QString::number(particle->qvelocity.y()) + ")";
    QPoint qpos = particle->qpoint + QPoint(5,5);
    painter->drawText(qpos,qs);
    delete painter;
}


void MainProgram::restartPoints(){
    this->particles.clear();
    for (int i = 0; i < this->particlesFirstIteration.size(); i++){
        int posx = this->particlesFirstIteration[i]->qpoint.x();
        int posy = this->particlesFirstIteration[i]->qpoint.y();
        int vx = this->particlesFirstIteration[i]->qvelocity.x();
        int vy = this->particlesFirstIteration[i]->qvelocity.y();
        Particle* pcopy = new Particle(posx, posy, vx, vy);

        this->particles.push_back(pcopy);
    }
}
