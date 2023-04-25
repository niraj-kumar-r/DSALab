#include <iostream>
#include "weightedMedian.h"

using namespace std;

int main()
{
    weightedMedianSolver solver = weightedMedianSolver();
    int choice = 0;
    int value = 0;
    float weight = 0;
    while (choice != 4)
    {
        cout << "\n";
        cout << "1. Insert value and weight" << endl;
        cout << "2. Get median" << endl;
        cout << "3. Remove value" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter weight: ";
            cin >> weight;
            solver.insert(value, weight);
            break;
        case 2:
            cout << "Median: " << solver.getMedian() << endl;
            break;
        case 3:
            cout << "Enter value to remove: ";
            cin >> value;
            solver.remove(value);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}