#include <iostream>
#include "weightedMedian.h"

using namespace std;

// int main()
// {
//     int numEntries = 10;
//     int values[] = {1, 2, 3, 4, 5};
//     float weights[] = {0.1, 4.2, 2.3, 0.4, 5.5};

//     weightedMedianSolver solver = weightedMedianSolver();

//     for (int i = 0; i < numEntries; i++)
//     {
//         solver.insert(values[i], weights[i]);
//     }
//     cout << "Median: " << solver.getMedian() << endl;
// }

// write menu based program to take input, show median, and remove value and exit

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