#ifndef POINT_H
#define POINT_H

#include <QPoint>

class Particle
{
public:
    QPoint qpoint;
    QPoint qvelocity;
    Particle(int x, int y, int vx, int vy);
    void updatePosition();
};

#endif // POINT_H
