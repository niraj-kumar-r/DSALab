#include "points.h"
#include "myAVLTree.h"
#include <iostream>

avlTreeNode_t::avlTreeNode_t(Point P)
{
    this->key = P.y;
    this->P = P;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
};

myAVLTree::myAVLTree()
{
    this->root = nullptr;
};

int myAVLTree::height(avlTreeNode_t *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
};

avlTreeNode_t *myAVLTree::rightRotate(avlTreeNode_t *y)
{
    avlTreeNode_t *x = y->left;
    avlTreeNode_t *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
};

avlTreeNode_t *myAVLTree::leftRotate(avlTreeNode_t *x)
{
    avlTreeNode_t *y = x->right;
    avlTreeNode_t *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
};

int myAVLTree::getBalance(avlTreeNode_t *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
};

avlTreeNode_t *myAVLTree::minValueNode(avlTreeNode_t *node)
{
    avlTreeNode_t *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
};

avlTreeNode_t *myAVLTree::insert(avlTreeNode_t *node, Point P)
{
    if (node == nullptr)
        return (new avlTreeNode_t(P));

    if (P.y < node->key)
    {
        node->left = insert(node->left, P);
        node->left->parent = node;
    }
    else if (P.y > node->key)
    {
        node->right = insert(node->right, P);
        node->right->parent = node;
    }
    else
    {
        return node;
    }

    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && P.y < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && P.y > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && P.y > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && P.y < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
};

avlTreeNode_t *myAVLTree::deleteNode(avlTreeNode_t *root, int key)
{

    if (root == nullptr)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        if ((root->left == nullptr) ||
            (root->right == nullptr))
        {
            avlTreeNode_t *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            avlTreeNode_t *temp = minValueNode(root->right);

            root->key = temp->key;
            root->P = temp->P;

            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    root->height = 1 + std::max(height(root->left),
                                height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
};

void myAVLTree::insert(Point P)
{
    root = insert(root, P);
};

void myAVLTree::deleteNode(int key)
{
    root = deleteNode(root, key);
};

int myAVLTree::getIntersectionCountInRange(avlTreeNode_t *node, int y1, int y2)
{
    if (node == nullptr)
        return 0;

    if (node->key >= y1 && node->key <= y2)
        return 1 + getIntersectionCountInRange(node->left, y1, y2) + getIntersectionCountInRange(node->right, y1, y2);

    else if (node->key < y1)
        return getIntersectionCountInRange(node->right, y1, y2);

    else
        return getIntersectionCountInRange(node->left, y1, y2);
};

int myAVLTree::getIntersectionCountInRange(int y1, int y2)
{
    return getIntersectionCountInRange(root, y1, y2);
};