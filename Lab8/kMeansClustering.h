#ifndef KMEANSCLUSTERING_H
#define KMEANSCLUSTERING_H

#include "points.h"
#include "myRBTree.h"
#include <vector>
#include <unordered_map>

class cluster : public myRBTree
{
public:
    Point centroid;
    cluster(Point p);
    void updateCentroid();
};

class my_graph
{
public:
    int numClusters;
    int numPoints;
    std::vector<cluster> clusters;
    std::vector<Point> points;
    std::unordered_map<Point, int> pointToCluster;
    my_graph(int numClusters);
    void setPoints(std::vector<Point> points);
    void addPoint(Point p);
    void removePoint(Point p);
    void doKMeans();
};

#endif