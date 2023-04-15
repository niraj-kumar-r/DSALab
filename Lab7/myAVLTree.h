#ifndef MY_AVL_TREE_H
#define MY_AVL_TREE_H

#include "points.h"

class avlTreeNode_t
{
public:
    int key;
    Point P;
    int height;
    avlTreeNode_t *left;
    avlTreeNode_t *right;
    avlTreeNode_t *parent;

    avlTreeNode_t(Point P);
};

class myAVLTree
{
private:
    avlTreeNode_t *root;

    int height(avlTreeNode_t *node);
    avlTreeNode_t *rightRotate(avlTreeNode_t *y);
    avlTreeNode_t *leftRotate(avlTreeNode_t *x);
    int getBalance(avlTreeNode_t *node);
    avlTreeNode_t *insert(avlTreeNode_t *node, Point P);
    avlTreeNode_t *minValueNode(avlTreeNode_t *node);
    avlTreeNode_t *deleteNode(avlTreeNode_t *root, int key);
    int getIntersectionCountInRange(avlTreeNode_t *node, int y1, int y2);
    // int getLevel(avlTreeNode_t *node);
    // void preOrder(avlTreeNode_t *node);
    // void inOrder(avlTreeNode_t *node);
    // void postOrder(avlTreeNode_t *node);
    // void printGivenLevel(avlTreeNode_t *root, int level);
    // avlTreeNode_t *search(avlTreeNode_t *node, int key);

public:
    myAVLTree();
    void insert(Point P);
    void deleteNode(int key);
    int getIntersectionCountInRange(int y1, int y2);
};

#endif