#ifndef GENERALISED_SEARCH_TREE_H
#define GENRALISED_SEARCH_TREE_H

#include <vector>
#include <queue>

class GeneralisedSearchTreeNode
{
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> values;
    std::vector<GeneralisedSearchTreeNode *> children;
    GeneralisedSearchTreeNode *parent;
};

class GeneralisedSearchTree
{
public:
    int mainFactor;
    GeneralisedSearchTreeNode *root;
    void insertVal(int num);
    void removeVal(int num);
    void levelOrderTraversal();
};

#endif