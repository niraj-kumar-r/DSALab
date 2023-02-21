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
        root->numberOfLeftChildren++;
    }
    else
    {
        root->rightChild = insertNode(value, root->rightChild);
        root->rightChild->parent = root;
        root->numberOfRightChildren++;
    }
    return root;
}

void BinarySearchTree::inorderTraversal(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->leftChild);
    cout << root->value << " ";
    inorderTraversal(root->rightChild);
}

void BinarySearchTree::preorderTraversal(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->value << " ";
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}

void BinarySearchTree::postorderTraversal(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    cout << root->value << " ";
}

void BinarySearchTree::levelorderTraversal(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    vector<BinarySearchTreeNode *> queue;
    queue.push_back(root);
    while (!queue.empty())
    {
        BinarySearchTreeNode *temp = queue[0];
        queue.erase(queue.begin());
        cout << temp->value << " ";
        if (temp->leftChild != nullptr)
        {
            queue.push_back(temp->leftChild);
        }
        if (temp->rightChild != nullptr)
        {
            queue.push_back(temp->rightChild);
        }
    }
}

bool BinarySearchTree::isBST(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    else if (root->leftChild != nullptr && root->leftChild->value > root->value)
    {
        return false;
    }
    else if (root->rightChild != nullptr && root->rightChild->value < root->value)
    {
        return false;
    }
    else
    {
        return isBST(root->leftChild) && isBST(root->rightChild);
    }
}

int BinarySearchTree::diameter(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);
        int leftDiameter = diameter(root->leftChild);
        int rightDiameter = diameter(root->rightChild);
        return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    }
}

int BinarySearchTree::height(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(root->leftChild), height(root->rightChild));
    }
}

BinarySearchTreeNode *BinarySearchTree::selectKthSmallest(int k, BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->numberOfLeftChildren + 1 == k)
    {
        return root;
    }
    else if (root->numberOfLeftChildren + 1 > k)
    {
        return selectKthSmallest(k, root->leftChild);
    }
    else
    {
        return selectKthSmallest(k - root->numberOfLeftChildren - 1, root->rightChild);
    }
}

BinarySearchTreeNode *BinarySearchTree::buildBinarySearchTreeFromInorderPostorder(int inorder[], int postorder[], int size)
{
    if (size == 0)
    {
        return nullptr;
    }
    else
    {
        BinarySearchTreeNode *root = new BinarySearchTreeNode(postorder[size - 1]);
        int i = 0;
        while (inorder[i] != postorder[size - 1])
        {
            i++;
        }
        root->leftChild = buildBinarySearchTreeFromInorderPostorder(inorder, postorder, i);
        root->rightChild = buildBinarySearchTreeFromInorderPostorder(inorder + i + 1, postorder + i, size - i - 1);
        return root;
    }
}