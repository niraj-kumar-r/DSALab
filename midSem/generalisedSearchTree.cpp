#include <iostream>
#include "generalisedSearchTree.h"
#include <algorithm>

using namespace std;

GeneralisedSearchTree::GeneralisedSearchTree(int m)
{
    this->mainFactor = m;
    this->TreeRoot = nullptr;
}

void GeneralisedSearchTree::insertVal(int num)
{
    insertVal(num, TreeRoot);
}

// void GeneralisedSearchTree::removeVal(int num)
// {
//     removeVal(num, TreeRoot);
// }

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

set<int>::iterator GeneralisedSearchTree::getMedian(GeneralisedSearchTreeNode *root)
{
    return next(root->keys.begin(), root->keys.size() / 2);
}

void GeneralisedSearchTree::fixNodeInsertion(GeneralisedSearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->keys.size() > mainFactor || root->children.size() > mainFactor - 1)
    {
        set<int>::iterator mkeyIt = this->getMedian(root);
        if (root->parent == nullptr)
        {
            root->parent = new GeneralisedSearchTreeNode();
            root->parent->children.push_back(root);
            if (TreeRoot == root)
            {
                TreeRoot = root->parent;
            }
        }
        root->parent->keys.insert(*mkeyIt);

        vector<GeneralisedSearchTreeNode *>::iterator it = find(root->parent->children.begin(), root->parent->children.end(), root);

        GeneralisedSearchTreeNode *n_child = new GeneralisedSearchTreeNode();
        n_child->parent = root->parent;

        move(root->keys.begin(), mkeyIt, inserter(n_child->keys, n_child->keys.begin()));
        root->keys.erase(root->keys.begin(), ++mkeyIt);

        move(root->children.begin(), root->children.begin() + (root->children.size() / 2), back_inserter(n_child->children));
        root->children.erase(root->children.begin(), root->children.begin() + (root->children.size() / 2));

        root->parent->children.insert(it, n_child);
        fixNodeInsertion(root->parent);
    }
}

void GeneralisedSearchTree::levelOrderTraversal()
{
    if (TreeRoot == nullptr)
    {
        return;
    }
    vector<GeneralisedSearchTreeNode *> q;
    q.push_back(TreeRoot);
    while (!q.empty())
    {
        GeneralisedSearchTreeNode *curr = q[0];
        q.erase(q.begin());
        auto it = curr->keys.begin();
        while (it != curr->keys.end())
        {
            cout << *it << " ";
            it++;
        }
        for (int i = 0, n = curr->children.size(); i < n; i++)
        {
            q.push_back(curr->children[i]);
        }
    }
}