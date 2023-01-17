#ifndef WEIGHTEDMEDIAN_H
#define WEIGHTEDMEDIAN_H

#define HEAP_SIZE 1000

class entry_t
{
private:
    int value;
    float weight;

public:
    entry_t(int value, int weight);
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
    int weightTotal;

public:
    heap_t();
    void insert(entry_t entry);
    entry_t remove();
    int getParent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);
    void heapify(int index);
    void buildHeap();
    void heapSort();
    int getWeightedMedian();
};

#endif