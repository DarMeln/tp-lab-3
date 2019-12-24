#include <cmath>
#include "Circle.h"
#define pi 3.14

Circle::Circle(double radius){
    Circle::setRadius(radius);
}

void Circle::setRadius(double rad){
    Circle::radius = rad;
    Circle::ference = 2*pi*rad;
    Circle::area = pi*pow(rad, 2);
}

void Circle::setFerence(double fer){
    Circle::ference = fer;
    Circle::radius = fer/(2*pi);
    Circle::area = pi*pow(Circle::radius, 2);
}

void Circle::setArea(double ar){
    Circle::area = ar;
    Circle::radius = sqrt(ar/pi);
    Circle::ference = 2*pi*Circle::radius;
}

double Circle::getRadius(){
    return Circle::radius;
}

double Circle::getFerence(){
    return Circle::ference;
}

double Circle::getArea(){
    return Circle::area;
}
