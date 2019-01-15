//
// Created by Avi on 12/01/2019.
//
#include "..\include\Cluster.h"
#ifndef CLUSTERS_CLUSTERFACTORY_H
#define CLUSTERS_CLUSTERFACTORY_H

class ClusterFactory{
    public:
        /**
         *
         * @param s The type of the needed cluster(SingleLinkCluster or AverageLinkCluster)
         * @return New cluster of type s
         */
        Cluster* make(std::string s);
};
#endif //CLUSTERS_CLUSTERFACTORY_H
