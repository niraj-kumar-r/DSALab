#include "mySkipLists.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    SkipList_t skipList;
    vector<int> vals = {12, 44, 25, 31, 38, 39, 20, 50, 55, 90, 3};
    for (auto &e : vals)
    {
        skipList.skipInsert(e);
    }
    skipList.print();
    skipList.remove(44);
    skipList.print();
    int a = 25;
    Node_t *n = skipList.skipSearch(a);
    if (n->getValue() == a)
    {
        cout << "Found: " << n->getValue() << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}