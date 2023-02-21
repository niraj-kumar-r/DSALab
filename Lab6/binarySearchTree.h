#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BinarySearchTreeNode
{
public:
    int value;
    int numberOfLeftChildren;
    int numberOfRightChildren;
    BinarySearchTreeNode *parent;
    BinarySearchTreeNode *leftChild;
    BinarySearchTreeNode *rightChild;
    BinarySearchTreeNode();
    BinarySearchTreeNode(int value);
    BinarySearchTreeNode(int value, BinarySearchTreeNode *parent);
};

class BinarySearchTree
{
public:
    BinarySearchTreeNode *root;
    BinarySearchTree();
    BinarySearchTreeNode *findNode(int value, BinarySearchTreeNode *root);
    BinarySearchTreeNode *predecessor(int value, BinarySearchTreeNode *root);
    BinarySearchTreeNode *successor(int value, BinarySearchTreeNode *root);
    BinarySearchTreeNode *deleteNode(int value, BinarySearchTreeNode *root);
    BinarySearchTreeNode *insertNode(int value, BinarySearchTreeNode *root);
    void preorderTraversal(BinarySearchTreeNode *root);
    void inorderTraversal(BinarySearchTreeNode *root);
    void postorderTraversal(BinarySearchTreeNode *root);
    void levelorderTraversal(BinarySearchTreeNode *root);
    bool isBST(BinarySearchTreeNode *root);
    int diameter(BinarySearchTreeNode *root);
    int height(BinarySearchTreeNode *root);
    int numberOfNodes(BinarySearchTreeNode *root);
    BinarySearchTreeNode *selectKthSmallest(int k, BinarySearchTreeNode *root);
    BinarySearchTreeNode *buildBinarySearchTreeFromInorderPostorder(int inorder[], int postorder[], int size);
    BinarySearchTreeNode *buildBinarySearchTreeFromInorderPreorder(int inorder[], int preorder[], int size);
};

#endif