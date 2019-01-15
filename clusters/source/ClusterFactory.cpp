//
// Created by Avi on 13/01/2019.
//
#include "..\include\ClusterFactory.h"

Cluster * ClusterFactory::make(std::string s) {
    if(s=="single link")
        return new SingleLinkCluster();
    if(s=="average link")
        return new AverageLinkCluster();
}
