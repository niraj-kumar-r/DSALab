#include <iostream>
#include "weightedMedian.h"

using namespace std;

int main()
{
    heap_t heap;
    entry_t entry;
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
            heap.insert(entry);
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            entry = heap.remove(index);
            cout << "Value: " << entry.getValue() << endl;
            cout << "Weight: " << entry.getWeight() << endl;
            break;
        case 3:
            cout << "Weighted Median: " << heap.getWeightedMedian() << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}