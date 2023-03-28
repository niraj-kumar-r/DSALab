#include <iostream>
#include "generalisedSearchTree.h"

using namespace std;

int main()
{
    GeneralisedSearchTree *tree = new GeneralisedSearchTree(3);
    tree->insertVal(8);
    tree->insertVal(9);
    tree->insertVal(10);
    tree->insertVal(11);
    tree->insertVal(15);
    tree->insertVal(20);
    tree->insertVal(17);
    tree->levelOrderTraversal();
}