#include <iostream>
#include "weightedMedian.h"

using namespace std;

int main()
{
    heap_t max_heap;
    heap_t min_heap;
    entry_t entry;
    int weightTotalCombined = 0;
    int value;
    float weight;
    int index;
    while (true)
    {
        cout << "\n\n\tMAIN MENU" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Get Weighted Median" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter weight: ";
            cin >> weight;
            entry.setValue(value);
            entry.setWeight(weight);
            selectiveInsert(entry, &max_heap, &min_heap);
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            // entry = remove(index);
            cout << "Value: " << entry.getValue() << endl;
            cout << "Weight: " << entry.getWeight() << endl;
            break;
        case 3:
            cout << "Weighted Median: " << max_heap.getEntry(0).getValue() << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

void selectiveInsert(entry_t entry, heap_t *max_heap, heap_t *min_heap)
{
    int weightTotalCombined = max_heap->getWeightTotal() + min_heap->getWeightTotal();

    if (entry.getValue() > min_heap->getEntry(0).getValue())
    {
        min_heap->insert(entry);
        min_heap->min_heapify_upwards(min_heap->getSize() - 1);
    }
    else
    {
        if ((max_heap->getWeightTotal() + entry.getWeight()) / (weightTotalCombined + entry.getWeight()) < 0.5)
        {
            max_heap->insert(entry);
            max_heap->max_heapify_upwards(max_heap->getSize() - 1);
        }
        else
        {
            min_heap->insert(entry);
            min_heap->min_heapify_upwards(min_heap->getSize() - 1);
            if ((max_heap->getWeightTotal() + min_heap->getEntry(0).getWeight()) / (weightTotalCombined + min_heap->getEntry(0).getWeight()) < 0.5)
            {
                entry = min_heap->remove(0);
                max_heap->insert(entry);
                max_heap->max_heapify_upwards(max_heap->getSize() - 1);
            }
        }
    }
}
