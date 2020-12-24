#include "particle.h"
#include "constants.h"
#include <iostream>
#include <cmath>

std::string Particle::optimizationFunction = StringConstants::deJongFunction1;
QPoint Particle::bestGlobalPos = QPoint();
float Particle::bestGlobalRes = ModelDefaultConstants::defaultBestGlobalRes;
float Particle::inercia1 = ModelDefaultConstants::defaultInercia1;
float Particle::inercia2 = ModelDefaultConstants::defaultInercia2;
float Particle::inercialWeight = ModelDefaultConstants::defaultInercialWeight;


Particle::Particle(int x, int y, int vx, int vy)
{
    this->qpoint = QPoint(x, y);
    this->qvelocity = QPoint(vx,vy);
    this->inerciaVelocity = 1;
    this->localRes = this->getOptimizationValue();
    this->bestLocalPos = this->qpoint;
    this->bestLocalRes = this->localRes;
    this->setOptimizationValue();
    if (Particle::bestGlobalPos.isNull()){
        Particle::bestGlobalPos = this->qpoint;
        Particle::bestGlobalRes = this->localRes;
    }

}


void Particle::updatePosition(){
    this->qpointnext = this->qpoint + this->qvelocity;

    std::cout << "x anterior: " << this->qpoint.x() << std::endl;
    std::cout << "x next: " <<this->qpointnext.x() << std::endl;

    if (this->qpointnext.x() > WindowConstants::WIDTH/2){
        this->qpointnext.setX(WindowConstants::WIDTH/2);
    }else if (this->qpointnext.x() < - WindowConstants::WIDTH/2){
        this->qpointnext.setX(- WindowConstants::WIDTH/2);
    }

    if (this->qpointnext.y() > WindowConstants::HEIGHT){
        this->qpointnext.setY(WindowConstants::HEIGHT);
    }else if (this->qpointnext.y() < - WindowConstants::HEIGHT/2){
        this->qpointnext.setY(- WindowConstants::HEIGHT/2);
    }

    this->recomputeVelocity();
    this->qpoint = this->qpointnext;
    this->qvelocity = this->qvelocitynext;
    this->setOptimizationValue();
}


void Particle::setOptimizationValue(){
    this->localRes = this->getOptimizationValue();
    this->checkIfBestLocalPos();
}


float Particle::getOptimizationValue(){
    float res;
    if (Particle::optimizationFunction == StringConstants::deJongFunction1){
        res = this->optimizationFunctionDeJong1();
    }
    else if (Particle::optimizationFunction == StringConstants::deJongFunction2){
        res = this->optimizationFunctionDeJong2();
    }
    else if (Particle::optimizationFunction == StringConstants::rastriginFunction6){
        res = this->optimizationFunctionRastrigin6();
    }
    else{
        res = 10000;
    }

    return res;
}

float Particle::optimizationFunctionDeJong1(){
    float x = 5.12 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    float y = 5.12 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    float res = pow(x,2) + pow(y,2);

    return res;
}

float Particle::optimizationFunctionDeJong2(){
    float x = 5.12 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    float y = 5.12 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    float res = 1*pow(x,2) + 2*pow(y,2);

    return res;
}

float Particle::optimizationFunctionRastrigin6(){
    float x = 3.5 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    float y = 3.5 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    float res = 10*2 + pow(x,2) + pow(y,2) - 10*cos(2*PI*x) - 10*cos(2*PI*y);

    return res;
}

void Particle::recomputeVelocity(){
   float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
   float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

   this->qvelocitynext = this->inerciaVelocity * this->qvelocity + Particle::inercia1 * r1 * (this->bestLocalPos - this->qpoint) + Particle::inercia2 * r2 * (this->bestGlobalPos - this->qpoint);
   this->inerciaVelocity = this->inerciaVelocity * Particle::inercialWeight;
}

void Particle::checkIfBestGlobalPos(){
    if (this->localRes < this->bestGlobalRes){
        Particle::bestGlobalRes = this->localRes;
        Particle::bestGlobalPos = this->qpoint;
    }
}

void Particle::checkIfBestLocalPos(){
    if (this->localRes < this->bestLocalRes){
        this->bestLocalRes = this->localRes;
        this->bestLocalPos = this->qpoint;
    }
}


QPoint Particle::getPrintPoint(){

    std::cout << "X on print from qpoint: " << this->qpoint.x() << std::endl;
    std::cout << "Y on print from qpoint: " << this->qpoint.y() << std::endl;
    int x = this->qpoint.x() + WindowConstants::WIDTH/2;
    int y = this->qpoint.y() + WindowConstants::HEIGHT/2;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

    QPoint qprintpoint = QPoint(x,y);
    return qprintpoint;
}

void Particle::clearGlobalVariables(){
    Particle::bestGlobalPos = QPoint();
    Particle::bestGlobalRes = ModelDefaultConstants::defaultBestGlobalRes;
}


void Particle::setOptimizationFunction(std::string function){
    Particle::optimizationFunction = function;
}




