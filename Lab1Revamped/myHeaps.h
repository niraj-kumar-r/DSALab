#ifndef MY_HEAPS_H
#define MY_HEAPS_H

#include <vector>

#define HEAP_SIZE 1000

class entry_t
{
private:
    int value;
    float weight;

public:
    entry_t();
    entry_t(int value, float weight);
    int getValue();
    float getWeight();
    void setValue(int value);
    void setWeight(float weight);
};

class heap_t
{
private:
    entry_t arr[HEAP_SIZE];
    int sizeArr;
    float weightTotal;
    bool minHeap;

public:
    heap_t();
    heap_t(bool minHeap);
    void insert(entry_t entry);
    entry_t getEntry(int index);
    int getSize();
    int getWeightTotal();
    entry_t remove(int index);
    entry_t remove(int value, bool &found);
    int getParent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);
    void min_heapify_upwards(int index);
    void min_heapify_downwards(int index);
    void max_heapify_upwards(int index);
    void max_heapify_downwards(int index);
    void buildHeap();
    void buildHeap(std::vector<int> entries, std::vector<float> weights);
};

#endif