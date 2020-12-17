#include "mainprogram.h"
#include "constants.h"
#include <iostream>


MainProgram::MainProgram()
{
    for (int i = 0; i<5; i++){
        Particle* p = new Particle(i*100,i*100+50, i+10, i+5);

        this->particles.push_back(p);
        std::cout << this->particles.at(i)->qpoint.y() << "      " << this->particles.at(i)->qpoint.ry() << std::endl;

    }

}

QPixmap MainProgram::refreshWindow(){
    QPixmap q = QPixmap(WindowConstants::WIDTH, WindowConstants::HEIGHT);
    q.fill(Qt::white);

    for (int i = 0; i < this->particles.size(); i++) // access by reference to avoid copying
    {
        Particle * p = this->particles.at(i);
        p->updatePosition();
        this->paintPoint(&q,p);
    }

    return q;
}


void MainProgram::paintPoint(QPixmap * q, Particle * particle){
    QPainter *painter = new QPainter(q);
    QPen linepen(Qt::red);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(10);
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(linepen);
    painter->drawPoint(particle->qpoint);
    delete painter;
}
