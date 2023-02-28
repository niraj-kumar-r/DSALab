#ifndef PROCESS_POINTS_H
#define PROCESS_POINTS_H

#include <queue>
#include <vector>
#include "points.h"

class Node_t
{
public:
    int key;
    Point P;
    bool isHorizontal;
    bool isLeft;
    int upper = 0;

    bool operator<(const Node_t &other) const
    {
        return key < other.key;
    }

    bool operator>(const Node_t &other) const
    {
        return key > other.key;
    }

    Node_t(int key, Point P, bool isHorizontal, bool isLeft);
    Node_t(Point P, bool isHorizontal, bool isLeft);
};

struct isSmallerMinHeapNode
{
    bool operator()(const Node_t &lhs, const Node_t &rhs) const
    {
        return lhs.key > rhs.key;
    }
};

// implement MinHeap as min priority queue
class MinHeap
{
private:
    std::priority_queue<Node_t, std::vector<Node_t>, isSmallerMinHeapNode> minHeap;
    void insert(Node_t node);
    void insert(Point P, bool isHorizontal, bool isLeft);

public:
    void insert(LineSegment L);
    Node_t extractMin();
    bool isEmpty();
};

#endif