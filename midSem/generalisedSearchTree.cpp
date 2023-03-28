#include <iostream>
#include "generalisedSearchTree.h"
#include <vector>
#include <queue>

using namespace std;

// implements a genralised search tree of order m,
// each node can have at most m children and m-1 keys
// every item inside the node is kept in non decreasing order

GeneralisedSearchTree::GeneralisedSearchTree(int m)
{
    this->mainFactor = m;
    this->TreeRoot = nullptr;
}

void GeneralisedSearchTree::insertVal(int num)
{
    insertVal(num, TreeRoot);
}

void GeneralisedSearchTree::removeVal(int num)
{
    removeVal(num, TreeRoot);
}

GeneralisedSearchTreeNode *GeneralisedSearchTree::searchVal(int num)
{
    return searchVal(num, TreeRoot);
}

GeneralisedSearchTreeNode *GeneralisedSearchTree::searchVal(int num, GeneralisedSearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    // else if (root->keys.find(num) != root->keys.end())
    // {
    //     return root;
    // }
    auto it = root->keys.begin();
    if (num < *it)
    {
        return searchVal(num, root->children[0]);
    }
    int i = 0;
    while (it != root->keys.end())
    {
        if (num == *it)
        {
            return root;
        }
        else if (num > *it)
        {
            i++;
        }
    }
    return searchVal(num, root->children[i]);
}
