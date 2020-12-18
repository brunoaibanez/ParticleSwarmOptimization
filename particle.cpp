#include "particle.h"
#include "constants.h"
#include <iostream>

Particle::Particle(int x, int y, int vx, int vy)
{
    this->qpoint = QPoint(x,y);
    this->qvelocity = QPoint(vx,vy);
}

void Particle::updatePosition(){
    this->qpoint += this->qvelocity;
    this->qpoint.setX(this->qpoint.x() % WindowConstants::WIDTH);
    this->qpoint.setY(this->qpoint.y() % WindowConstants::HEIGHT);
}
