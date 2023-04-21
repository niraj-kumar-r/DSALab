#ifndef WEIGHTED_MEDIAN_H
#define WEIGHTED_MEDIAN_H

#include "myHeaps.h"

class weightedMedianSolver
{
private:
    heap_t min_heap = heap_t(true);
    heap_t max_heap = heap_t(false);

    int weightedMedian;
    void balanceHeaps();

public:
    void insert(int value, float weight);
    void remove(int value);
    int getMedian();
};

#endif