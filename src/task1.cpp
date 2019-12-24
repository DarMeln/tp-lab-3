#include "task1.h"

double calcDelta(Circle rope){
    double oldRad = rope.getRadius();
    rope.setFerence(rope.getFerence() + 0.001);
    return rope.getRadius() - oldRad;
}

double calcCost(Circle pool){
    Circle road(pool.getRadius()+1);
    double roadArea = road.getArea() - pool.getArea();
    double roadCost = roadArea * 1000;
    double fenceCost = pool.getFerence() * 2000;
    return roadCost + fenceCost;
}
