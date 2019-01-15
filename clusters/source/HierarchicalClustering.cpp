//
// Created by Avi on 12/01/2019.
//
#include "..\include\HierarchicalClustering.h"
HierarchicalClustering::HierarchicalClustering(unsigned int K,std::string s): required_number_of_clusters(K),type(s){
    clusters=new std::vector<Cluster *>();
}
void HierarchicalClustering::init(const std::vector<Point > &v) {
    std:: vector <Point >::const_iterator iter;
    Cluster *c;
    for(iter=v.begin() ; iter!=v.end() ; iter++){
        c=factory.make(type);
        c->addPoint(*iter);
        clusters->push_back(c);
    }
}
void HierarchicalClustering::clustering() {
    unsigned int first,second;
    double minDistance;
    double tempDistance;
    while(clusters->size() != required_number_of_clusters){
        Cluster *c1,*c2;
        minDistance=std:: numeric_limits<double >::max();
        for(unsigned int i=0 ; i<clusters->size() ; i++){
            c1=clusters->at(i);
            for(unsigned int j=i+1 ;j<clusters->size() ; j++){
                c2=clusters->at(j);
                tempDistance=c1->distanceFromCluster(*c2);
                if(minDistance > tempDistance ){
                    first=i;
                    second=j;
                    minDistance=tempDistance;
                }
            }
        }
        c1=clusters->at(first);
        c2=clusters->at(second);
        clusters->erase(clusters->begin()+second);
        clusters->erase(clusters->begin()+first);
        c1->merge(*c2);
        clusters->push_back(c1);
        delete(c2);
    }
}
const std:: vector<Cluster *>& HierarchicalClustering ::getClusters() const {
    return *clusters;
}
HierarchicalClustering :: ~HierarchicalClustering(){
    Cluster *c;
    const unsigned  int N= clusters->size()-1;
    for(int i=N ; i>-1 ;i--){
        c=clusters->at(i);
        delete(c);
    }
    clusters->clear();
    delete(clusters);
}