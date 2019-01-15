//
// Created by Avi on 12/01/2019.
//
#ifndef CLUSTERS_CLUSTER_H
#define CLUSTERS_CLUSTER_H
#include <fstream>
#include <iostream>
#include "Point.h"
#include <set>
#include <limits>
#include <iterator>
#include <iostream>
#include <algorithm>
class Cluster  {
private:
    std::set< Point > *cluster;
public:
    Cluster();
     /**
      * Merge given cluster to this cluster
      * Do not change the given cluster
      * @param c The other cluster
      */
    void merge(const Cluster &c);//merging cluster c to this cluster

     /**
      * Adding new point to the cluster
      * @param p A point in the plain
      */
    void addPoint(const Point &p);
    /**
     * Printing the points in the cluster to the standard output
     */
    void printCluster() const ;
    /**
     * Printing the points to a given file
     * @param file The file to which the points will be printed
     */
    void printCluster(std:: ofstream &file) const ;

    /**
     *
     * @param c The other cluster
     * @return The distance from c
     */
    virtual double distanceFromCluster(const Cluster &c) const =0;
    /**
     *
     * @return
     */
    std::set<Point>* getCluster() const;
    ~Cluster();
};
class SingleLinkCluster : public Cluster{//for single link
public:
    /**
     *
     * @param c The other cluster
     * @return The distance from c, computed by single link
     */
    double distanceFromCluster(const Cluster &c) const ;

};
class AverageLinkCluster : public Cluster{
public:
    /**
     *
     * @param c The other cluster
     * @return The distance from c, computed by average link
     */
    double distanceFromCluster(const Cluster &c) const ;
};



#endif //CLUSTERS_CLUSTER_H
