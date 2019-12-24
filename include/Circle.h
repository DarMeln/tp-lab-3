#pragma once

class Circle{
    public:
        Circle(double radius);
        void setRadius(double rad);
        void setFerence(double fer);
        void setArea(double ar);
        double getRadius();
        double getFerence();
        double getArea();

    private:
        double radius, ference, area;
};
