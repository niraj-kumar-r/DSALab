#include "processPoints.h"
#include <queue>
#include <iostream>

Node_t::Node_t(int key, Point P, bool isHorizontal, bool isLeft)
{
    this->key = key;
    this->P = P;
    this->isHorizontal = isHorizontal;
    this->isLeft = isLeft;
}

Node_t::Node_t(Point P, bool isHorizontal, bool isLeft)
{
    this->key = P.x;
    this->P = P;
    this->isHorizontal = isHorizontal;
    this->isLeft = isLeft;
}

void MinHeap::insert(Node_t node)
{
    minHeap.push(node);
}

void MinHeap::insert(Point P, bool isHorizontal, bool isLeft)
{
    Node_t node(P, isHorizontal, isLeft);
    minHeap.push(node);
}

void MinHeap::insert(LineSegment L)
{
    if (L.P1.y == L.P2.y)
    {
        if (L.P1.x < L.P2.x)
        {
            insert(L.P1, true, true);
            insert(L.P2, true, false);
        }
        else
        {
            insert(L.P2, true, true);
            insert(L.P1, true, false);
        }
    }
    else if (L.P1.x == L.P2.x)
    {
        if (L.P1.y < L.P2.y)
        {
            Node_t node(L.P1, false, true);
            node.upper = L.P2.y;
            insert(node);
        }
        else
        {
            Node_t node(L.P2, false, true);
            node.upper = L.P1.y;
            insert(node);
        }
    }
    else
    {
        std::cout << "Error: Line segment is not horizontal or vertical.";
    }
}

Node_t MinHeap::extractMin()
{
    Node_t node = minHeap.top();
    minHeap.pop();
    return node;
}

bool MinHeap::isEmpty()
{
    return minHeap.empty();
}
