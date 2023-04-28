#include <iostream>

#include "hash_table.h"
using namespace std;

int main()
{
  cout << "\nWelcome to the perfect hash table!" << endl;
  hash_table h;
  int choice;
  while (true)
  {
    cout << "\nChoices:\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Print\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter the #elements followed by the elements:" << endl;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        int j;
        cin >> j;
        h.insert(j);
        cout << "Inserted " << j << endl;
      }
      break;
    case 2:
      cout << "Enter the element to delete: ";
      cin >> n;
      h.Delete(n);
      cout << "Deleted " << n << endl;
      break;
    case 3:
      cout << "\nPrinting the hash table:\n";
      h.print();
      break;
    case 4:
      return 0;
    default:
      cout << "Invalid choice" << endl;
    }
  }
}
