#include "particle.h"
#include "constants.h"
#include <iostream>
#include <cmath>

std::string Particle::optimizationFunction = StringConstants::deJongFunction1;
QPoint Particle::bestGlobalPos = QPoint();
float Particle::bestGlobalRes = 1;
float Particle::inercia1 = 1;
float Particle::inercia2 = 1;


Particle::Particle(int x, int y, int vx, int vy)
{
    this->qpoint = QPoint(x % WindowConstants::WIDTH, y % WindowConstants::HEIGHT);
    this->qvelocity = QPoint(vx,vy);
    this->inerciaVelocity = 1;
    this->setOptimizationValue();

}


void Particle::updatePosition(){
    this->qpointnext = this->qpoint + this->qvelocity;

    if (this->qpointnext.x() > WindowConstants::WIDTH){
        this->qpointnext.setX(WindowConstants::WIDTH);
    }else if (this->qpointnext.x() < 0){
        this->qpoint.setX(0);
    }

    if (this->qpointnext.y() > WindowConstants::WIDTH){
        this->qpointnext.setY(WindowConstants::WIDTH);
    }else if (this->qpointnext.y() < 0){
        this->qpoint.setY(0);
    }

    //this->recomputeVelocity();
    this->qpoint = this->qpointnext;
    this->qvelocity = this->qvelocitynext;
}


void Particle::setOptimizationValue(){
    this->localRes = this->getOptimizationValue();
}


float Particle::getOptimizationValue(){
    float res;
    if (Particle::optimizationFunction == StringConstants::deJongFunction1){
        res = this->optimizationFunctionDeJong1();
    }
    else{
        res = 10000;
    }

    return res;
}

float Particle::optimizationFunctionDeJong1(){
    float x = (this->qpoint.x() - WindowConstants::WIDTH / 2 );
    float y = (this->qpoint.y() - WindowConstants::HEIGHT / 2);

    float res = pow(x,2) + pow(y,2);

    return res;
}





