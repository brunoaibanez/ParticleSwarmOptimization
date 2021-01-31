#ifndef POINT_H
#define POINT_H

#include <QPoint>

#define PI 3.14159265

class Particle
{
public:
    Particle(int x, int y, int vx, int vy);
    void updatePosition();
    void recomputeVelocity();

    void checkIfBestGlobalPos();
    void checkIfBestLocalPos();

    double optimizationFunctionDeJong1();
    double optimizationFunctionDeJong2();
    double optimizationFunctionRastrigin6();
    double optimizationFunctionRosenbrock();

    float getOptimizationValue();
    void setOptimizationValue();

    static void setOptimizationFunction(std::string function);
    static void clearGlobalVariables();

    QPoint getPrintPoint();
    QPoint qpoint, qpointnext;
    QPoint qvelocity, qvelocitynext;
    float inerciaVelocity;
    QPoint bestLocalPos;
    double bestLocalRes;
    double localRes;

    static std::string optimizationFunction;
    static QPoint bestGlobalPos;
    static float bestGlobalRes;
    static float inercia1;
    static float inercia2;
    static float inercialWeight;

};

#endif // POINT_H
