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
    std::vector <Particle *> particles;
};

#endif // MAINPROGRAM_H
