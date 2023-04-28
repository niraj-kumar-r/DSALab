#include "PerfectHash.h"
#include <iostream>

using namespace std;

// write a menu driven program to
// 1. insert an element
// 2. delete an element
// 3. find an element
// 4. print the hash table
// 5. exit

int main()
{
    HashTable ht;
    int choice = 0, x, z;
    while (choice != 5)
    {
        cout << "\n1. Insert an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Find an element" << endl;
        cout << "4. Print the hash table" << endl;
        cout << "5. Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "Enter the number of element to be inserted: ";
            cin >> x;
            cout << "Enter the elements : ";
            for (int i = 0; i < x; i++)
            {
                cin >> z;
                ht.insertElement(z);
            }
            break;
        case 2:
            cout << "Enter the element to be deleted: ";
            cin >> x;
            ht.deleteElement(x);
            break;
        case 3:
            cout << "Enter the element to be found: ";
            cin >> x;
            ht.findElement(x);
            break;
        case 4:
            ht.print();
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}