#include <iostream>
#include "weightedMedian.h"

using namespace std;

int weightedMedianSolver::getMedian()
{
    if (max_heap.getSize() == 0)
    {
        return -1;
    }
    return weightedMedian;
};

void weightedMedianSolver::insert(int value, float weight)
{
    entry_t entry = entry_t(value, weight);

    if (max_heap.getSize() == 0)
    {
        max_heap.insert(entry);
        return;
    }
    else if (value < max_heap.getEntry(0).getValue())
    {
        max_heap.insert(entry);
    }
    else
    {
        min_heap.insert(entry);
    }

    balanceHeaps();
}

void weightedMedianSolver::remove(int value)
{
    if (max_heap.getSize() == 0)
    {
        return;
    }
    bool found = false;
    entry_t entry = max_heap.remove(value, found);
    if (!found)
    {
        entry = min_heap.remove(value, found);
    }

    if (found)
    {
        balanceHeaps();
        cout << "Removed " << value << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
}

void weightedMedianSolver::balanceHeaps()
{
    while (max_heap.getWeightTotal() > min_heap.getWeightTotal())
    {
        entry_t entry = max_heap.remove(0);
        min_heap.insert(entry);
    }

    while (max_heap.getWeightTotal() + min_heap.getEntry(0).getWeight() < min_heap.getWeightTotal() - min_heap.getEntry(0).getWeight())
    {
        entry_t entry = min_heap.remove(0);
        max_heap.insert(entry);
    }

    weightedMedian = max_heap.getEntry(0).getValue();
}