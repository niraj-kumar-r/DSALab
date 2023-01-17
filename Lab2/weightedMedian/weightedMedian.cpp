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

entry_t heap_t::remove(int index)
{
    if (index >= sizeArr)
    {
        throw invalid_argument("Index out of bounds");
    }
    else
    {
        entry_t temp = arr[index];
        arr[index] = arr[sizeArr - 1]; // replace the element to be removed with the last element
        sizeArr--;
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

void heap_t::heapify(int index)
{
    int left = getLeftChild(index);
    int right = getRightChild(index);
    int parent = index;

    int maxEntry = max(arr[parent].getValue(), arr[left].getValue(), arr[right].getValue());

    if (maxEntry != arr[parent].getValue() && maxEntry == arr[left].getValue())
    {
        swap(arr[parent], arr[left]);
        heapify(left);
    }
    else if (maxEntry != arr[parent].getValue() && maxEntry == arr[right].getValue())
    {
        swap(arr[parent], arr[right]);
        heapify(right);
    }
}

void heap_t::buildHeap()
{
    for (int i = (sizeArr / 2) - 1; i >= 0; i--)
    {
        heapify(i);
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
        heapify(0);
    }
}

int heap_t::getWeightedMedian()
{
    heapSort();
    int median = -1;
    int weight = arr[0].getWeight();
    int i = 0;
    while (weight < weightTotal / 2)
    {
        weight += arr[i + 1].getWeight();
        median = arr[i].getValue();
        i++;
    }
    return median;
}
