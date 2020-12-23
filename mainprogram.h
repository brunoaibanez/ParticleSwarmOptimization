#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <vector>
#include "particle.h"

class MainProgram
{
public:
    MainProgram();
    QPixmap refreshWindow();
    void paintPoint(QPixmap * q, Particle * particle);
    void restartPoints();
    void setNumberOfParticles(int numberOfParticles);
    void updatePointsPositions();
    void setPixmap();
    std::vector <Particle *> particles;
    std::vector <Particle *> particlesFirstIteration;
    QPixmap * qpixMap;

};

#endif // MAINPROGRAM_H
