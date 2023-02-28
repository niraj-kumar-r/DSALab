#ifndef PROCESS_POINTS_H
#define PROCESS_POINTS_H

#include <queue>

class Point
{
public:
    Point(int x, int y);
    int x;
    int y;
};

class MinHeapNode
{
public:
    int key;
    Point P;
    bool isHorizontal;
    bool isLeft;

    bool operator<(const MinHeapNode &other) const
    {
        return key < other.key;
    }

    bool operator>(const MinHeapNode &other) const
    {
        return key > other.key;
    }

    MinHeapNode(int key, Point P, bool isHorizontal, bool isLeft);
    MinHeapNode();
};

// implement MinHeap as min priority queue
class MinHeap
{
public:
    priority_queue<MinHeapNode> minHeap;
    void insert(MinHeapNode node);
    void insert(Point P, bool isHorizontal, bool isLeft);
    MinHeapNode extractMin();
    bool isEmpty();
};

#endif