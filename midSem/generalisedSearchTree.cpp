#include <iostream>
#include "generalisedSearchTree.h"
#include <vector>
#include <queue>

using namespace std;

// implements a generalised search tree of order m,
// similar to a binary search tree
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
    // if (num < *it)
    // {
    //     return searchVal(num, root->children[0]);
    // }
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
        else
        {
            break;
        }
        it++;
    }
    return searchVal(num, root->children[i]);
}

GeneralisedSearchTreeNode *GeneralisedSearchTree::findNodeForInsert(int num, GeneralisedSearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->children.size() == 0)
    {
        return root;
    }
    auto it = root->keys.begin();
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
        else
        {
            break;
        }
        it++;
    }
    return findNodeForInsert(num, root->children[i]);
}

void GeneralisedSearchTree::insertVal(int num, GeneralisedSearchTreeNode *root)
{
    GeneralisedSearchTreeNode *node = findNodeForInsert(num, TreeRoot);
    if (node == nullptr)
    {
        TreeRoot = new GeneralisedSearchTreeNode();
        TreeRoot->keys.insert(num);
        return;
    }
    node->keys.insert(num);
    if (node->keys.size() > mainFactor)
    {
        fixNodeInsertion(node);
    }
}

void fixNodeInsertion(GeneralisedSearchTreeNode *root)
{
}
