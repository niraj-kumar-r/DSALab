#include <iostream>
#include <vector>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    int inorder[] = {4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
    int postorder[] = {4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};

    BinarySearchTree *bst = new BinarySearchTree();
    bst->root = bst->buildBinarySearchTreeFromInorderPostorder(inorder, postorder, sizeof(inorder) / sizeof(inorder[0]));
    bst->inorderTraversal(bst->root);
    cout << endl;
    bst->preorderTraversal(bst->root);
    cout << endl;

    // check every function in the binary search tree class
    BinarySearchTreeNode *node = bst->findNode(22, bst->root);
    cout << "findNode(22): " << node->value << endl;

    node = bst->predecessor(22, bst->root);
    cout << "predecessor(22): " << node->value << endl;

    node = bst->successor(22, bst->root);
    cout << "successor(22): " << node->value << endl;

    node = bst->selectKthSmallest(5, bst->root);
    cout << "selectKthSmallest(5): " << node->value << endl;

    cout << "isBST: " << bst->isBST(bst->root) << endl;

    cout << "diameter: " << bst->diameter(bst->root) << endl;

    cout << "height: " << bst->height(bst->root) << endl;

    bst->levelorderTraversal(bst->root);
    cout << endl;

    cout << "deleting 22..." << endl;
    bst->root = bst->deleteNode(22, bst->root);
    bst->inorderTraversal(bst->root);
    cout << endl;
    bst->preorderTraversal(bst->root);
    cout << endl;

    cout << "inserting 22..." << endl;
    bst->root = bst->insertNode(22, bst->root);
    bst->inorderTraversal(bst->root);
    cout << endl;
    bst->preorderTraversal(bst->root);
    cout << endl;
}