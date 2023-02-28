#include <iostream>
#include "processPoints.h"

using namespace std;

int main()
{
    int lines[][4] = {{1, 0, 3, 0}, {2, 1, 2, 3}, {4, 0, 4, 2}, {5, 1, 5, 3}, {6, 0, 8, 0}, {7, 1, 7, 3}, {9, 0, 9, 2}};
    int n = sizeof(lines) / sizeof(lines[0]);

    MinHeap minHeap;
    for (int i = 0; i < n; i++)
    {
        Point P1(lines[i][0], lines[i][1]);
        Point P2(lines[i][2], lines[i][3]);
        LineSegment L(P1, P2);
        minHeap.insert(L);
    }

    while (!minHeap.isEmpty())
    {
        Node_t node = minHeap.extractMin();
        cout << node.P.x << " " << node.P.y << endl;
    }
};