#include "myRBTree.h"
#include <iostream>

using namespace std;

myRBTree::myRBTree()
{
    root = nullptr;
    numNodes = 0;
    sumX = 0;
    sumY = 0;
}

void myRBTree::insert(Point p)
{
    Node *n = new Node(p);
    insert(n);
}

void myRBTree::insert(Node *n)
{
    Node *y = nullptr;
    Node *x = root;
    while (x != nullptr)
    {
        y = x;
        if (n->p.x < x->p.x || (n->p.x == x->p.x && n->p.y < x->p.y))
            x = x->left;
        else
            x = x->right;
    }
    n->parent = y;
    if (y == nullptr)
        root = n;
    else if (n->p.x < y->p.x || (n->p.x == y->p.x && n->p.y < y->p.y))
        y->left = n;
    else
        y->right = n;
    numNodes++;
    sumX += n->p.x;
    sumY += n->p.y;
    fixInsert(n);
}

void myRBTree::remove(Point p)
{
    Node *n = find(p);
    if (n != nullptr)
    {
        remove(n);
    }
}

void myRBTree::remove(Node *n)
{
    Node *y = n;
    Node *x;
    bool yOriginalColor = y->isRed;
    if (n->left == nullptr)
    {
        x = n->right;
        transplant(n, n->right);
    }
    else if (n->right == nullptr)
    {
        x = n->left;
        transplant(n, n->left);
    }
    else
    {
        y = minimum(n->right);
        yOriginalColor = y->isRed;
        x = y->right;
        if (y->parent == n)
            x->parent = y;
        else
        {
            transplant(y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        transplant(n, y);
        y->left = n->left;
        y->left->parent = y;
        y->isRed = n->isRed;
    }
    if (!yOriginalColor)
        fixRemove(x);
    numNodes--;
    sumX -= n->p.x;
    sumY -= n->p.y;
    delete n;
}

Node *myRBTree::find(Point p)
{
    return find(root, p);
}

Node *myRBTree::find(Node *n, Point p)
{
    if (n == nullptr || (n->p.x == p.x && n->p.y == p.y))
        return n;
    if (p.x < n->p.x || (p.x == n->p.x && p.y < n->p.y))
        return find(n->left, p);
    else
        return find(n->right, p);
}

void myRBTree::print()
{
    print(root);
}

void myRBTree::print(Node *n)
{
    if (n == nullptr)
        return;
    print(n->left);
    cout << "(" << n->p.x << ", " << n->p.y << ") ";
    print(n->right);
}

void myRBTree::rotateLeft(Node *n)
{
    Node *y = n->right;
    n->right = y->left;
    if (y->left != nullptr)
        y->left->parent = n;
    y->parent = n->parent;
    if (n->parent == nullptr)
        root = y;
    else if (n == n->parent->left)
        n->parent->left = y;
    else
        n->parent->right = y;
    y->left = n;
    n->parent = y;
}

void myRBTree::rotateRight(Node *n)
{
    Node *y = n->left;
    n->left = y->right;
    if (y->right != nullptr)
        y->right->parent = n;
    y->parent = n->parent;
    if (n->parent == nullptr)
        root = y;
    else if (n == n->parent->right)
        n->parent->right = y;
    else
        n->parent->left = y;
    y->right = n;
    n->parent = y;
}

void myRBTree::fixInsert(Node *n)
{
    while (n != root && n->parent->isRed)
    {
        if (n->parent == n->parent->parent->left)
        {
            Node *y = n->parent->parent->right;
            if (y != nullptr && y->isRed)
            {
                n->parent->isRed = false;
                y->isRed = false;
                n->parent->parent->isRed = true;
                n = n->parent->parent;
            }
            else
            {
                if (n == n->parent->right)
                {
                    n = n->parent;
                    rotateLeft(n);
                }
                n->parent->isRed = false;
                n->parent->parent->isRed = true;
                rotateRight(n->parent->parent);
            }
        }
        else
        {
            Node *y = n->parent->parent->left;
            if (y != nullptr && y->isRed)
            {
                n->parent->isRed = false;
                y->isRed = false;
                n->parent->parent->isRed = true;
                n = n->parent->parent;
            }
            else
            {
                if (n == n->parent->left)
                {
                    n = n->parent;
                    rotateRight(n);
                }
                n->parent->isRed = false;
                n->parent->parent->isRed = true;
                rotateLeft(n->parent->parent);
            }
        }
    }
    root->isRed = false;
}

void myRBTree::fixRemove(Node *n)
{
    while (n != root && !n->isRed)
    {
        if (n == n->parent->left)
        {
            Node *w = n->parent->right;
            if (w->isRed)
            {
                w->isRed = false;
                n->parent->isRed = true;
                rotateLeft(n->parent);
                w = n->parent->right;
            }
            if (!w->left->isRed && !w->right->isRed)
            {
                w->isRed = true;
                n = n->parent;
            }
            else
            {
                if (!w->right->isRed)
                {
                    w->left->isRed = false;
                    w->isRed = true;
                    rotateRight(w);
                    w = n->parent->right;
                }
                w->isRed = n->parent->isRed;
                n->parent->isRed = false;
                w->right->isRed = false;
                rotateLeft(n->parent);
                n = root;
            }
        }
        else
        {
            Node *w = n->parent->left;
            if (w->isRed)
            {
                w->isRed = false;
                n->parent->isRed = true;
                rotateRight(n->parent);
                w = n->parent->left;
            }
            if (!w->right->isRed && !w->left->isRed)
            {
                w->isRed = true;
                n = n->parent;
            }
            else
            {
                if (!w->left->isRed)
                {
                    w->right->isRed = false;
                    w->isRed = true;
                    rotateLeft(w);
                    w = n->parent->left;
                }
                w->isRed = n->parent->isRed;
                n->parent->isRed = false;
                w->left->isRed = false;
                rotateRight(n->parent);
                n = root;
            }
        }
    }
    n->isRed = false;
}

void myRBTree::transplant(Node *u, Node *v)
{
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
}
