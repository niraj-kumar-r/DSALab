#include <iostream>
#include "generalisedSearchTree.h"
#include <vector>
#include <set>
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

void GeneralisedSearchTree::fixNodeInsertion(GeneralisedSearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->keys.size() > mainFactor || root->children.size() > mainFactor - 1)
    {
        // get median of root->keys
        int mkey = getMedian(root);
        // root->keys.erase(mkey);
        if (root->parent == nullptr)
        {
            root->parent = new GeneralisedSearchTreeNode();
            root->parent->children.push_back(root);
        }
        root->parent->keys.insert(mkey);
        auto it = root->parent->children.begin();
        while (*it != root)
        {
            it++;
        }
        GeneralisedSearchTreeNode *n_child = new GeneralisedSearchTreeNode();
        n_child->parent = root->parent;
        auto r_it = root->keys.begin();
        int i = 0;
        while (*r_it < mkey)
        {
            n_child->keys.insert(*r_it);
            r_it++;
            i++;
        }
        set<int> out;
        // set_difference(root->keys.begin(), root->keys.end(), n_child->keys.begin(), n_child->keys.end(), out.begin());
        r_it++;
        while (r_it != root->keys.end())
        {
            out.insert(*r_it);
        }
        root->keys = out;
        for (int j = 0; j < i; j++)
        {
            n_child->children.push_back(root->children[j]);
        }
        while (i--)
        {
            root->children.pop_back();
        }
        root->parent->children.insert(it, n_child);

        fixNodeInsertion(root->parent);
    }
}

int GeneralisedSearchTree::getMedian(GeneralisedSearchTreeNode *root)
{
    int k = root->keys.size();
    int median = 0;
    if (k % 2 == 0)
    {
        median = k / 2;
    }
    else
    {
        median = (k + 1) / 2;
    }
    auto it = root->keys.begin();
    for (int i = 0; i < median; i++)
    {
        it++;
    }
    return *it;
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
        }
        cout << endl;
        for (int i = 0, n = curr->children.size(); i < n; i++)
        {
            q.push_back(curr->children[i]);
        }
    }
}