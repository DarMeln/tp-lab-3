#include "task1.h"

double Circle::calcDelta(){
    Circle rope(6378.1);
    double oldRad = 6378.1;
    rope.setFerence(rope.getFerence() + 0.001);
    return rope.getRadius() - oldRad;
}

double Circle::calcCost(){
    Circle pool(3.0);
    Circle road(pool.getRadius()+1.0);
    double roadArea = road.getArea() - pool.getArea();
    double roadCost = roadArea * 1000;
    double fenceCost = pool.getFerence() * 2000;
    return roadCost + fenceCost;
}
