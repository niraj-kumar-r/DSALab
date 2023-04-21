#include "myHeaps.h"
#include <iostream>

using namespace std;

// Constructor
entry_t::entry_t()
{
    value = 0;
    weight = 0;
}

// Constructor
entry_t::entry_t(int value, float weight)
{
    this->value = value;
    this->weight = weight;
}

// Returns value
int entry_t::getValue()
{
    return value;
}

// Returns weight
float entry_t::getWeight()
{
    return weight;
}

// Sets value
void entry_t::setValue(int value)
{
    this->value = value;
}

// Sets weight
void entry_t::setWeight(float weight)
{
    this->weight = weight;
}

// Constructor
heap_t::heap_t()
{
    sizeArr = 0;
    weightTotal = 0;
    minHeap = true;
}

// Constructor
heap_t::heap_t(bool minHeap)
{
    sizeArr = 0;
    weightTotal = 0;
    this->minHeap = minHeap;
}

// Inserts entry into heap
void heap_t::insert(entry_t entry)
{
    arr[sizeArr] = entry;
    sizeArr++;
    weightTotal += entry.getWeight();
    if (minHeap)
    {
        min_heapify_upwards(sizeArr - 1);
    }
    else
    {
        max_heapify_upwards(sizeArr - 1);
    }
}

// Returns entry at index
entry_t heap_t::getEntry(int index)
{
    return arr[index];
}

// Returns size of heap
int heap_t::getSize()
{
    return sizeArr;
}

// Returns total weight of heap
int heap_t::getWeightTotal()
{
    return weightTotal;
}

// Removes entry at index
entry_t heap_t::remove(int index)
{
    entry_t entry = arr[index];
    arr[index] = arr[sizeArr - 1];
    sizeArr--;
    weightTotal -= entry.getWeight();
    if (minHeap)
    {
        min_heapify_downwards(index);
    }
    else
    {
        max_heapify_downwards(index);
    }
    return entry;
}

// Returns index of parent
int heap_t::getParent(int index)
{
    return (index - 1) / 2;
}

// Returns index of left child
int heap_t::getLeftChild(int index)
{
    return (2 * index) + 1;
}

// Returns index of right child
int heap_t::getRightChild(int index)
{
    return (2 * index) + 2;
}

// Maintains min heap property by swapping upwards
void heap_t::min_heapify_upwards(int index)
{
    if (index == 0)
    {
        return;
    }
    int parent = getParent(index);
    if (arr[index].getWeight() < arr[parent].getWeight())
    {
        entry_t temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;
        min_heapify_upwards(parent);
    }
}

// Maintains min heap property by swapping downwards
void heap_t::min_heapify_downwards(int index)
{
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    int smallest = index;
    if (leftChild < sizeArr && arr[leftChild].getWeight() < arr[smallest].getWeight())
    {
        smallest = leftChild;
    }
    if (rightChild < sizeArr && arr[rightChild].getWeight() < arr[smallest].getWeight())
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        entry_t temp = arr[index];
        arr[index] = arr[smallest];
        arr[smallest] = temp;
        min_heapify_downwards(smallest);
    }
}

// Maintains max heap property by swapping upwards
void heap_t::max_heapify_upwards(int index)
{
    if (index == 0)
    {
        return;
    }
    int parent = getParent(index);
    if (arr[index].getWeight() > arr[parent].getWeight())
    {
        entry_t temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;
        max_heapify_upwards(parent);
    }
}

// Maintains max heap property by swapping downwards
void heap_t::max_heapify_downwards(int index)
{
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    int largest = index;
    if (leftChild < sizeArr && arr[leftChild].getWeight() > arr[largest].getWeight())
    {
        largest = leftChild;
    }
    if (rightChild < sizeArr && arr[rightChild].getWeight() > arr[largest].getWeight())
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        entry_t temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        max_heapify_downwards(largest);
    }
}

// build heap
void heap_t::buildHeap()
{
    for (int i = sizeArr / 2; i >= 0; i--)
    {
        if (minHeap)
        {
            min_heapify_downwards(i);
        }
        else
        {
            max_heapify_downwards(i);
        }
    }
}

// build heap from vector
void heap_t::buildHeap(vector<int> entries, vector<float> weights)
{
    for (int i = 0; i < entries.size(); i++)
    {
        arr[i] = entry_t(entries[i], weights[i]);
    }
    sizeArr = entries.size();
    buildHeap();
}