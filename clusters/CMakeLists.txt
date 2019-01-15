cmake_minimum_required(VERSION 3.12)
project(clusters)

set(CMAKE_CXX_STANDARD 98)

add_executable(clusters include/Point.h source/Point.cpp source/Simulator.cpp include/Cluster.h source/Cluster.cpp include/HierarchicalClustering.h source/HierarchicalClustering.cpp include/ClusterFactory.h source/ClusterFactory.cpp include/Cluster.h source/Cluster.cpp)