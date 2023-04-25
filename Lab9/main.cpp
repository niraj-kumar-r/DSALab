#include <iostream>

#include "hash_table.h"
using namespace std;

int main() {
  cout << "Welcome to the perfect hash table!" << endl;
  cout << "Provide the #elements followed by the elements:"<<endl;
  hash_table h;
  int n;
  cin>>n;
  for (int i=0; i<n; i++){
    int j;
    cin>>j;
    h.insert(j);
    cout<<"Inserted "<<j<<endl;
  }
  h.print();
  return 0;
}
