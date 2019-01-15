//
// Created by Avi on 11/01/2019.
//
#include "..\include\Point.h"

Point:: Point( double x1, double x2) : x(x1), y(x2){}
Point:: Point(const Point &other) : x(other.x), y(other.y) {}
double Point:: getX() const {return x;}
double Point:: getY() const {return y;}
double Point::euclideanDistance(const Point &p1, const Point &p2) {
    double x1 = p1.x;
    double y1 = p1.y;
    double x2 = p2.x;
    double y2 = p2.y;
    double sum=pow(x1-x2,2)+pow(y1-y2,2);
    return sqrt(sum);
}
bool Point::operator==(const Point &other) const {
    return x==other.getX()&&y==other.getY();
}

void Point:: operator=(const Point &other){
    this->x=other.getX();
    this->y=other.getY();
}
bool Point::operator<(const Point &other) const{
    return euclideanDistance(*this,Point(0,0))<euclideanDistance(other,Point(0,0));
}
Point ::~Point() {}