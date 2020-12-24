#ifndef POINT_H
#define POINT_H

#include <QPoint>

class Particle
{
public:
    Particle(int x, int y, int vx, int vy);
    void updatePosition();
    void recomputeVelocity();

    void checkIfBestGlobalPos();
    void checkIfBestLocalPos();

    float optimizationFunctionDeJong1();
    float optimizationFunctionDeJong2();

    float getOptimizationValue();
    void setOptimizationValue();

    static void setOptimizationFunction(std::string function);
    static void clearGlobalVariables();

    QPoint getPrintPoint();
    QPoint qpoint, qpointnext;
    QPoint qvelocity, qvelocitynext;
    float inerciaVelocity;
    QPoint bestLocalPos;
    float bestLocalRes;
    float localRes;

    static std::string optimizationFunction;
    static QPoint bestGlobalPos;
    static float bestGlobalRes;
    static float inercia1;
    static float inercia2;

};

#endif // POINT_H
