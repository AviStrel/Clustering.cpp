//
// Created by Avi on 11/01/2019.
//
#include <Math.h>
#ifndef CLUSTERS_POINT_H
#define CLUSTERS_POINT_H
/**
 * Represent a point in R^2
 */
class Point{
    private:
        double x;
        double y;
    public:
        /**
         * Construct a point in the plain
         * @param x1
         * @param x2
         */
        Point(double x1, double x2);
        /**
         * Copy constructor
         * @param other The point to be copied
         */
        Point(const Point &other);
        ~Point();
        /**
         *
         * @param p1 The first point
         * @param p2 The second point
         * @return The euclidean distance between the points
         */
        static double euclideanDistance(const Point &p1,const Point &p2);
        /**
         *
         * @return x
         */
        double getX() const ;
        /**
         *
         * @return y
         */
        double getY() const ;
        /**
         *
         * @param other A point in the plain
         * @return True if and only if this->x==other.x and this->y==other.y
         */
        bool operator==(const Point &other) const ;
        void operator=(const Point &other);
        /**
         *
         * @param other A point in the plain
         * @return True if and only if euclideanDistance(this,(0,0))<euclideanDistance(other,(0,0))
         */
        bool operator <(const Point& other) const;

};
#endif //CLUSTERS_POINT_H
