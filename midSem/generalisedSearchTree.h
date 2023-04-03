#ifndef GENERALISED_SEARCH_TREE_H
#define GENRALISED_SEARCH_TREE_H

#include <vector>
// #include <queue>
#include <set>

class GeneralisedSearchTreeNode
{
public:
    std::set<int> keys;
    std::vector<GeneralisedSearchTreeNode *> children;
    GeneralisedSearchTreeNode *parent = nullptr;
};

class GeneralisedSearchTree
{
public:
    int mainFactor;
    GeneralisedSearchTreeNode *TreeRoot;

    GeneralisedSearchTree(int m);

    void insertVal(int num);
    // void removeVal(int num);
    GeneralisedSearchTreeNode *searchVal(int num);
    void levelOrderTraversal();

private:
    void insertVal(int num, GeneralisedSearchTreeNode *root);
    // void removeVal(int num, GeneralisedSearchTreeNode *root);
    GeneralisedSearchTreeNode *searchVal(int num, GeneralisedSearchTreeNode *root);
    GeneralisedSearchTreeNode *findNodeForInsert(int num, GeneralisedSearchTreeNode *root);
    void fixNodeInsertion(GeneralisedSearchTreeNode *root);
    set<int>::iterator getMedian(GeneralisedSearchTreeNode *root);
};

#endif