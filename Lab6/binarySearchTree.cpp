#include <iostream>
#include <vector>
#include "binarySearchTree.h"

using namespace std;

BinarySearchTreeNode::BinarySearchTreeNode()
{
    value = NULL;
    numberOfLeftChildren = 0;
    numberOfRightChildren = 0;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}

BinarySearchTreeNode::BinarySearchTreeNode(int value)
{
    this->value = value;
    numberOfLeftChildren = 0;
    numberOfRightChildren = 0;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}

BinarySearchTreeNode::BinarySearchTreeNode(int value, BinarySearchTreeNode *parent)
{
    this->value = value;
    numberOfLeftChildren = 0;
    numberOfRightChildren = 0;
    this->parent = parent;
    leftChild = nullptr;
    rightChild = nullptr;
}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTreeNode *BinarySearchTree::findNode(int value, BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->value == value)
    {
        return root;
    }
    else if (root->value > value)
    {
        return findNode(value, root->leftChild);
    }
    else
    {
        return findNode(value, root->rightChild);
    }
}

BinarySearchTreeNode *BinarySearchTree::predecessor(int value, BinarySearchTreeNode *root)
{
    BinarySearchTreeNode *node = findNode(value, root);
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->leftChild != nullptr)
    {
        BinarySearchTreeNode *temp = node->leftChild;
        while (temp->rightChild != nullptr)
        {
            temp = temp->rightChild;
        }
        return temp;
    }
    else
    {
        BinarySearchTreeNode *temp = node->parent;
        while (temp != nullptr && temp->value > node->value)
        {
            temp = temp->parent;
        }
        return temp;
    }
}

BinarySearchTreeNode *BinarySearchTree::successor(int value, BinarySearchTreeNode *root)
{
    BinarySearchTreeNode *node = findNode(value, root);
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->rightChild != nullptr)
    {
        BinarySearchTreeNode *temp = node->rightChild;
        while (temp->leftChild != nullptr)
        {
            temp = temp->leftChild;
        }
        return temp;
    }
    else
    {
        BinarySearchTreeNode *temp = node->parent;
        while (temp != nullptr && temp->value < node->value)
        {
            temp = temp->parent;
        }
        return temp;
    }
}

BinarySearchTreeNode *BinarySearchTree::deleteNode(int value, BinarySearchTreeNode *root)
{
    BinarySearchTreeNode *node = findNode(value, root);
    if (node == nullptr)
    {
        return root;
    }
    else if (node->leftChild == nullptr && node->rightChild == nullptr)
    {
        if (node->parent == nullptr)
        {
            root = nullptr;
        }
        else if (node->parent->leftChild == node)
        {
            node->parent->leftChild = nullptr;
        }
        else
        {
            node->parent->rightChild = nullptr;
        }
        delete node;
        return root;
    }
    else if (node->leftChild == nullptr)
    {
        if (node->parent == nullptr)
        {
            root = node->rightChild;
        }
        else if (node->parent->leftChild == node)
        {
            node->parent->leftChild = node->rightChild;
        }
        else
        {
            node->parent->rightChild = node->rightChild;
        }
        node->rightChild->parent = node->parent;
        delete node;
        return root;
    }
    else if (node->rightChild == nullptr)
    {
        if (node->parent == nullptr)
        {
            root = node->leftChild;
        }
        else if (node->parent->leftChild == node)
        {
            node->parent->leftChild = node->leftChild;
        }
        else
        {
            node->parent->rightChild = node->leftChild;
        }
        node->leftChild->parent = node->parent;
        delete node;
        return root;
    }
    else
    {
        BinarySearchTreeNode *temp = successor(value, root);
        node->value = temp->value;
        return deleteNode(temp->value, root);
    }
}

BinarySearchTreeNode *BinarySearchTree::insertNode(int value, BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        root = new BinarySearchTreeNode(value);
    }
    else if (root->value > value)
    {
        root->leftChild = insertNode(value, root->leftChild);
        root->leftChild->parent = root;
    }
    else
    {
        root->rightChild = insertNode(value, root->rightChild);
        root->rightChild->parent = root;
    }
    return root;
}
