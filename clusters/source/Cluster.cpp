//
// Created by Avi on 12/01/2019.
//

#include "../include/Cluster.h"
Cluster ::Cluster(){
    cluster= new std::set< Point >();
}

void Cluster::addPoint(const Point &p) {
    cluster->insert(p);
}
void Cluster::merge(const Cluster &c) {
    std::merge(cluster->begin(),cluster->end(),c.cluster->begin(),c.cluster->end(),std::inserter(*cluster,cluster->begin()));
}
void Cluster::printCluster() const {
    std:: set <Point >::const_iterator iter;
    for (iter = cluster->begin(); iter != cluster->end(); iter++)
        std::cout <<"x = " <<(*iter).getX() <<  " y = "<< (*iter).getY() <<   std::endl;

}

void Cluster::printCluster(std::ofstream &file) const {
    for(std:: set<Point>::const_iterator iter=cluster->begin() ;iter!=cluster->end() ; iter++){
        file << "x = " <<(*iter).getX() <<  " y = "<< (*iter).getY() <<"\n";
    }
}
std::set<Point>* Cluster::getCluster() const {
    std::set<Point > *res=new std::set<Point>();
    std:: set <Point >::const_iterator iter;
    for(iter=cluster->begin() ; iter!=cluster->end() ;iter++){
        res->insert(*iter);
    }
    return res;

}
Cluster :: ~Cluster(){
   while(!cluster->empty()){
       cluster->erase(cluster->begin());
   }
    delete(cluster);
}

double SingleLinkCluster:: distanceFromCluster(const Cluster &c) const  {
    double distance = std::numeric_limits<double>::max();
    std::set<Point> *c1 = getCluster();
    std::set<Point> *c2 = c.getCluster();

    for (std::set<Point>::const_iterator iter1 = c1->begin(); iter1 != c1->end(); iter1++) {
        for (std::set<Point>::const_iterator iter2 = c2->begin(); iter2 != c2->end(); iter2++) {
            distance = std::min(distance, Point::euclideanDistance(*iter1, *iter2));
        }

    }
    /**
     * Deleting c1 and c2
     */
    delete(c1);
    delete(c2);
    return distance;
}
double AverageLinkCluster:: distanceFromCluster(const Cluster &c) const {
    double sumOfDistances=0.0;
    std::set<Point > *c1=getCluster();
    std::set<Point > *c2=c.getCluster();

    for(std:: set <Point>::const_iterator iter1=c1->begin() ;iter1 !=c1->end() ;iter1++) {
        for (std:: set <Point>::const_iterator iter2 = c2->begin(); iter2 != c2->end(); iter2++) {
            sumOfDistances += Point::euclideanDistance(*iter1, *iter2);
        }
    }

    sumOfDistances=sumOfDistances/(c1->size()*c2->size());
    /**
     * Deleting c1 and c2
     */
    delete(c1);
    delete(c2);

    return sumOfDistances;
}
