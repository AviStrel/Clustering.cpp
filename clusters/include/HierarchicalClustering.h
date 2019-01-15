//
// Created by Avi on 12/01/2019.
//
#include "..\include\ClusterFactory.h"
#include <vector>
#include <algorithm>
#ifndef CLUSTERS_HIERARCHICALCLUSTERING_H
#define CLUSTERS_HIERARCHICALCLUSTERING_H

class HierarchicalClustering {
    private:
        std:: vector<Cluster * > *clusters;
        const std::string type;
        ClusterFactory factory;
        const unsigned int required_number_of_clusters;
    public:
        /**
         *
         * @param K The number of clusters requested
         * @param s The type of the clustering algorithms(single link or average link)
         */
        HierarchicalClustering(unsigned int K,std::string s);
        /**
         * Initializing
         * Create a new cluster for every point in v
         * @param v Vector of points
         */
        void init(const std::vector<Point > &v);
        /**
         *clustering the points
         * Use getClusters() to get the clusters
         */
        void clustering();
        /**
         *
         * @return The clusters
         */
        const std:: vector<Cluster *>& getClusters() const;
        /**
         * Destructor
         */
        ~HierarchicalClustering();

};


#endif //CLUSTERS_HIERARCHICALCLUSTERING_H
