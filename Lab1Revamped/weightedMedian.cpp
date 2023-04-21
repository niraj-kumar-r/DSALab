#include <iostream>
#include "myHeaps.h"

using namespace std;

int main(void)
{
    // use one min_heap and one max_heap, to balance the max_heap, where
    // the max_heap_weight/total_weight <= 0.5, then the median is the
    // root of the max_heap

    heap_t min_heap(true);
    heap_t max_heap(false);

    int n = 10;
    // cin >> n;

    int values[10] = {1, 8, 3, 4, 5, 6, 7, 8, 9, 10};
    float weights[10] = {1, 2.7, 2, 1, 0.1, 1, 5, 1, 0.5, 1};

    for (int i = 0; i < n; i++)
    {
        int value = values[i];
        float weight = weights[i];
        // cin >> value >> weight;

        entry_t entry(value, weight);

        if (min_heap.getSize() == 0)
        {
            min_heap.insert(entry);
        }
        else
        {
            if (entry.getValue() < min_heap.getEntry(0).getValue())
            {
                max_heap.insert(entry);
            }
            else
            {
                min_heap.insert(entry);
            }
        }

        if (max_heap.getWeightTotal() > min_heap.getWeightTotal())
        {
            entry_t entry = max_heap.remove(0);
            min_heap.insert(entry);
        }
        else if (min_heap.getWeightTotal() - max_heap.getWeightTotal() > 1)
        {
            entry_t entry = min_heap.remove(0);
            max_heap.insert(entry);
        }

        if (min_heap.getWeightTotal() == max_heap.getWeightTotal())
        {
            cout << (min_heap.getEntry(0).getValue() + max_heap.getEntry(0).getValue()) / 2.0 << endl;
        }
        else
        {
            cout << min_heap.getEntry(0).getValue() << endl;
        }
    }
}