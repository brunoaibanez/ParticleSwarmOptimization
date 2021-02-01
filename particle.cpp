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
float Particle::maxVelocity = ModelDefaultConstants::defaultMaxVelocity;


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
    double res;
    if (Particle::optimizationFunction == StringConstants::deJongFunction1){
        res = this->optimizationFunctionDeJong1();
    }
    else if (Particle::optimizationFunction == StringConstants::deJongFunction2){
        res = this->optimizationFunctionDeJong2();
    }
    else if (Particle::optimizationFunction == StringConstants::rastriginFunction6){
        res = this->optimizationFunctionRastrigin6();
    }
    else if (Particle::optimizationFunction == StringConstants::rosenbrockFunction){
        res = this->optimizationFunctionRosenbrock();
    }
    else if (Particle::optimizationFunction == StringConstants::griewankFunction){
        res = this->optimizationFunctionGriewank();
    }
    else if (Particle::optimizationFunction == StringConstants::schafferFunction){
        res = this->optimizationFunctionSchaffer();
    }
    else{
        res = 10000;
    }

    return res;
}

double Particle::optimizationFunctionDeJong1(){
    double x = 5.12 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 5.12 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = pow(x,2) + pow(y,2);

    return res;
}

double Particle::optimizationFunctionDeJong2(){
    double x = 5.12 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 5.12 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = 1*pow(x,2) + 2*pow(y,2);

    return res;
}

double Particle::optimizationFunctionRastrigin6(){
    double x = 3.5 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 3.5 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = 10*2 + pow(x,2) + pow(y,2) - 10*cos(2*PI*x) - 10*cos(2*PI*y);

    return res;
}

double Particle::optimizationFunctionRosenbrock(){
    double x = 2.0 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 3.0 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = pow(1-x,2) + 100*pow((y-pow(x,2)),2);

    return res;
}

double Particle::optimizationFunctionGriewank(){
    double x = 50.0 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 50.0 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = (pow(x,2) + pow(y,2))/ 1000 - cos(x/1) * cos(y/sqrt(2.0)) + 1;

    return res;
}

double Particle::optimizationFunctionSchaffer(){
    double x = 100.0 * this->qpoint.x() / (WindowConstants::WIDTH/2);
    double y = 100.0 * this->qpoint.y() / (WindowConstants::HEIGHT/2);

    double res = 0.5 - (pow(sin(sqrt(pow(x,2)+pow(y,2))),2)-0.5) / pow(1+0.001*(pow(x,2)+pow(y,2)),2) ;

    return res;
}

void Particle::recomputeVelocity(){
   //float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //Uncomment one of the two to get the deterministic algorithm
   //float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
   float r1 = 0.5;
   float r2 = 0.5;

   this->qvelocitynext = this->inerciaVelocity * this->qvelocity + Particle::inercia1 * r1 * (this->bestLocalPos - this->qpoint) + Particle::inercia2 * r2 * (this->bestGlobalPos - this->qpoint);
   float norm = sqrt(pow(this->qvelocitynext.x(), 2) + pow(this->qvelocitynext.y(), 2));
   if (norm > this->maxVelocity){
       this->qvelocitynext = this->qvelocitynext * this->maxVelocity / norm;
   }
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

    int x = this->qpoint.x() + WindowConstants::WIDTH/2;
    int y = this->qpoint.y() + WindowConstants::HEIGHT/2;

    QPoint qprintpoint = QPoint(x,y);
    return qprintpoint;
}

void Particle::clearGlobalVariables(){
    Particle::bestGlobalPos = QPoint();
    Particle::bestGlobalRes = ModelDefaultConstants::defaultBestGlobalRes;
}


void Particle::setOptimizationFunction(std::string function){
    std::cout << function << std::endl;
    Particle::optimizationFunction = function;
}




