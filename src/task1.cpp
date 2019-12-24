#include <iostream>
#include "task1.h"

double calcDelta(){
    Circle rope(6378.1);
    double oldRad = 6378.1;
    rope.setFerence(rope.getFerence() + 1.0);
    return rope.getRadius() - oldRad;
}

double calcCost(){
    Circle pool(3);
    Circle road(pool.getRadius()+1);
    double roadCost = (road.getArea() - pool.getArea()) * 1000;
    double fenceCost = road.getFerence() * 2000;
    return roadCost + fenceCost;
}
