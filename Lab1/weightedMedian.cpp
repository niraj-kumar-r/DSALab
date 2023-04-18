#include "weightedMedian.h"
#include <iostream>

using namespace std;

entry_t::entry_t(int value, float weight)
{
    this->value = value;
    this->weight = weight;
}

entry_t::entry_t()
{
    value = 0;
    weight = 0;
}

int entry_t::getValue()
{
    return value;
}

float entry_t::getWeight()
{
    return weight;
}

void entry_t::setValue(int value)
{
    this->value = value;
}

void entry_t::setWeight(float weight)
{
    this->weight = weight;
}

heap_t::heap_t()
{
    sizeArr = 0;
    weightTotal = 0;
}

void heap_t::insert(entry_t entry)
{
    if (sizeArr >= HEAP_SIZE)
    {
        throw invalid_argument("Heap Overflow");
    }
    else
    {
        arr[sizeArr] = entry;
        sizeArr++;
        weightTotal += entry.getWeight();
    }
}

entry_t heap_t::getEntry(int index)
{
    if (index >= sizeArr || index < 0)
    {
        throw invalid_argument("Index out of bounds");
    }
    else
    {
        return arr[index];
    }
}

int heap_t::getSize()
{
    return sizeArr;
}

int heap_t::getWeightTotal()
{
    return weightTotal;
}

entry_t heap_t::remove(int index)
{
    if (index >= sizeArr || index < 0)
    {
        throw invalid_argument("Index out of bounds");
    }
    else
    {
        entry_t temp = arr[index];
        arr[index] = arr[sizeArr - 1]; // replace the element to be removed with the last element
        sizeArr--;
        max_heapify_upwards(index);    // max_heapify_upwards the tree
        weightTotal -= temp.getWeight();
        return temp;
    }
}

int heap_t::getParent(int index)
{
    if (index == 0)
    {
        return -1;
    }
    else
    {
        return (index - 1) / 2;
    }
}

int heap_t::getLeftChild(int index)
{
    int left = 2 * index + 1;
    if (left >= sizeArr)
    {
        return -1;
    }
    else
    {
        return left;
    }
}

int heap_t::getRightChild(int index)
{
    int right = 2 * index + 2;
    if (right >= sizeArr)
    {
        return -1;
    }
    else
    {
        return right;
    }
}

void heap_t::max_heapify_upwards(int index)
{
    int parent = getParent(index);
    if (parent == -1)
    {
        return;
    }
    int maxEntry = max(arr[index].getValue(), arr[parent].getValue());
    if (maxEntry != arr[parent].getValue())
    {
        swap(arr[index], arr[parent]);
        max_heapify_upwards(parent);
    }
}

void heap_t::max_heapify_downwards(int index)
{
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int maxEntry = arr[index].getValue();
    int maxIndex = index;
    if (left != -1 && arr[left].getValue() > maxEntry)
    {
        maxEntry = arr[left].getValue();
        maxIndex = left;
    }
    if (right != -1 && arr[right].getValue() > maxEntry)
    {
        maxEntry = arr[right].getValue();
        maxIndex = right;
    }
    if (maxIndex != index)
    {
        swap(arr[index], arr[maxIndex]);
        max_heapify_downwards(maxIndex);
    }
}

void heap_t::min_heapify_downwards(int index)
{
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int minEntry = arr[index].getValue();
    int minIndex = index;
    if (left != -1 && arr[left].getValue() < minEntry)
    {
        minEntry = arr[left].getValue();
        minIndex = left;
    }
    if (right != -1 && arr[right].getValue() < minEntry)
    {
        minEntry = arr[right].getValue();
        minIndex = right;
    }
    if (minIndex != index)
    {
        swap(arr[index], arr[minIndex]);
        min_heapify_downwards(minIndex);
    }
}

void heap_t::min_heapify_upwards(int index)
{
    int parent = getParent(index);
    if (parent == -1)
    {
        return;
    }
    int minEntry = min(arr[index].getValue(), arr[parent].getValue());
    if (minEntry != arr[parent].getValue())
    {
        swap(arr[index], arr[parent]);
        min_heapify_upwards(parent);
    }
}

void heap_t::buildHeap()
{
    for (int i = (sizeArr / 2) - 1; i >= 0; i--)
    {
        max_heapify_upwards(i);
    }
}

void heap_t::heapSort()
{
    buildHeap();
    int s = sizeArr;
    for (int i = s - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        s--;
        max_heapify_upwards(0);
    }
}

// int heap_t::getWeightedMedian()
// {
//     heapSort();
//     int medianIndex = 0;
//     int weight = 0;
//     int i = 0;
//     while (weight < weightTotal / 2)
//     {
//         weight += arr[i].getWeight();
//         medianIndex = i;
//         i++;
//     }
//     return arr[medianIndex].getValue();
// }
