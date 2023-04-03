#include <iostream>
#include "generalisedSearchTree.h"

using namespace std;

int main()
{
    GeneralisedSearchTree *tree = new GeneralisedSearchTree(3);
    tree->insertVal(8);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(9);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(10);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(11);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(15);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(20);
    tree->levelOrderTraversal();
    cout << endl;
    tree->insertVal(17);
    tree->levelOrderTraversal();
}