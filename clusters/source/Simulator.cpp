//
// Created by Avi on 11/01/2019.
//
#include "..\include\HierarchicalClustering.h"

int main(int argc, char **argv){
    std:: string path=argv[3];
    std:: string inputFileName=path;
    std:: string outputFileName=path;
    inputFileName.append(argv[1]);
    outputFileName.append(argv[2]);
    std:: ifstream inputFile;
    std:: ofstream outputFile(outputFileName.c_str());
    inputFile.open(inputFileName.c_str());
    if(!inputFile){
        std:: cout <<"Could not open input file" <<std::endl;
        exit(-1);
    }
    if(!outputFile){
        std:: cout <<"Could not open output file" <<std::endl;
        exit(-2);
    }
    //**************** Set up the data ****************
    unsigned int lineNumber=0,numberOfClusters,delimit;
    std::string thisLine(""),type;
    double x,y;
    std:: vector<Point> points=std::vector<Point>();
    while(std::getline(inputFile,thisLine)){
        if(lineNumber == 0) type =thisLine;
        if(lineNumber == 1) numberOfClusters = std:: atoi(thisLine.c_str());
        if(lineNumber>1){
            delimit = thisLine.find(",");
            x = std :: atof(thisLine.substr(0,delimit).c_str());
            y = std :: atof(thisLine.substr(delimit+1,thisLine.size()).c_str());
            points.push_back(Point(x,y));
        }
        lineNumber++;
    }
    //**************** Clustering ****************
    HierarchicalClustering h= HierarchicalClustering(numberOfClusters,type);
    h.init(points);
    h.clustering();
    //**************** Printing to the output file ****************
    std:: vector<Cluster * > v=h.getClusters();
    for(std::vector<Cluster *>::const_iterator iter=v.begin(); iter!=v.end() ;){
        outputFile << "Cluster :\n";
        (*iter)->printCluster(outputFile);
        if(++iter!=v.end()) outputFile << "\n";
    }
    inputFile.close();
    outputFile.close();

}
