#ifndef POINT_H
#define POINT_H

#include <QPoint>

class Particle
{
public:
    Particle(int x, int y, int vx, int vy);
    void updatePosition();
    void recomputeVelocity();
    static void setOptimizationFunction(std::string function);
    void checkIfBestGlobalPos();
    float optimizationFunctionDeJong1();
    float getOptimizationValue();
    void setOptimizationValue();
    QPoint qpoint, qpointnext;
    QPoint qvelocity, qvelocitynext;
    float inerciaVelocity;
    QPoint bestPosX;
    float bestLocalRes;
    float localRes;

    static std::string optimizationFunction;
    static QPoint bestGlobalPos;
    static float bestGlobalRes;
    static float inercia1;
    static float inercia2;

};

#endif // POINT_H
