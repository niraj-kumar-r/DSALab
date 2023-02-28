#ifndef AVL_TREE_H
#define AVL_TREE_H

class AvlNode
{
public:
    int key;
    Point P;
    AvlNode *left;
    AvlNode *right;
    AvlNode *parent;
    int height;
    AvlNode(int key, Point P, AvlNode *left, AvlNode *right, AvlNode *parent, int height);
    AvlNode(int key, Point P);
    AvlNode();
};

class AvlTree
{
public:
    AvlNode *root;
    AvlTree();
    void insert(int value);
    void remove(int value);
    void print();
};

#endif