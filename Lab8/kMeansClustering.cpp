#include "kMeansClustering.h"
#include <iostream>
using namespace std;

cluster::cluster()
{
    centroid = Point(NULL, NULL);
}

cluster::cluster(Point p)
{
    centroid = p;
}

void cluster::updateCentroid()
{
    if (root == NULL)
    {
        centroid = Point(NULL, NULL);
        return;
    }
    else
    {
        centroid = Point(sumX / numNodes, sumY / numNodes);
        return;
    }
}

GraphPoint::GraphPoint()
{
    cluster = NULL;
}

GraphPoint::GraphPoint(Point p, int cluster)
{
    this->x = p.x;
    this->y = p.y;
    this->cluster = cluster;
}

GraphPoint::GraphPoint(int x, int y, int cluster)
{
    this->x = x;
    this->y = y;
    this->cluster = cluster;
}

GraphPoint::GraphPoint(int x, int y)
{
    this->x = x;
    this->y = y;
    this->cluster = NULL;
}

GraphPoint::GraphPoint(Point p)
{
    this->x = p.x;
    this->y = p.y;
    this->cluster = NULL;
}

my_graph::my_graph(int numClusters)
{
    this->numClusters = numClusters;
    numPoints = 0;
    clusters = std::vector<cluster>(numClusters);
    graphPoints = std::vector<GraphPoint>();
}

void my_graph::setPoints(std::vector<GraphPoint> points)
{
    graphPoints = points;
    numPoints = points.size();
    assignRandomCentroids();
}

void my_graph::assignRandomCentroids()
{
    for (int i = 0; i < numClusters; i++)
    {
        clusters[i] = cluster(graphPoints[i]);
    }
}

void my_graph::addPoint(GraphPoint p)
{
    graphPoints.push_back(p);
    numPoints++;
}

void my_graph::removePoint(GraphPoint p)
{
    for (int i = 0; i < numPoints; i++)
    {
        if (graphPoints[i] == p)
        {
            graphPoints.erase(graphPoints.begin() + i);
            numPoints--;
            return;
        }
    }
}