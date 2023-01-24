#include "mySkipLists.h"
#include <iostream>
#include <limits>

using namespace std;

// Node_t class

// Constructor
Node_t::Node_t()
{
    value = 0;
    max_level = 0;
}

// Constructor
Node_t::Node_t(int value)
{
    this->value = value;
    max_level = 0;
}

// Get value
int Node_t::getValue()
{
    return value;
}

// Get max level
int Node_t::getMaxLevel()
{
    return max_level;
}

// Get next
Node_t *Node_t::getNext(int level)
{
    return next[level];
}

// Set value
void Node_t::setValue(int value)
{
    this->value = value;
}

// Set max level
void Node_t::setMaxLevel(int max_level)
{
    this->max_level = max_level;
}

// Set next
void Node_t::setNext(Node_t *next, int level)
{
    this->next[level] = next;
}

// End of Node_t class

// SkipList_t class

// Constructor
SkipList_t::SkipList_t()
{
    neg_inf = new Node_t(numeric_limits<int>::min());
    pos_inf = new Node_t(numeric_limits<int>::max());
    neg_inf->setMaxLevel(0);
    pos_inf->setMaxLevel(0);
    neg_inf->setNext(pos_inf, 0);
    height = 0;
}

// Get height
int SkipList_t::getHeight()
{
    return height;
}

// Get number of nodes
int SkipList_t::getNumberOfNodes()
{
    return numberOfNodes;
}

// Get negative infinity
Node_t *SkipList_t::getNegInf()
{
    return neg_inf;
}

// Get positive infinity
Node_t *SkipList_t::getPosInf()
{
    return pos_inf;
}

// Insert
// void SkipList_t::insert(int value)
// {
//     Node_t *current = neg_inf;
//     Node_t *update[height + 1];
//     for (int i = height; i >= 0; i--)
//     {
//         while (current->getNext(i)->getValue() < value)
//         {
//             current = current->getNext(i);
//         }
//         update[i] = current;
//     }
//     current = current->getNext(0);
//     if (current->getValue() == value)
//     {
//         return;
//     }
//     int new_level = 0;
//     while (rand() % 2 == 1)
//     {
//         new_level++;
//     }
//     if (new_level > height)
//     {
//         for (int i = height + 1; i <= new_level; i++)
//         {
//             update[i] = neg_inf;
//         }
//         height = new_level;
//     }
//     Node_t *new_node = new Node_t(value);
//     new_node->setMaxLevel(new_level);
//     for (int i = 0; i <= new_level; i++)
//     {
//         new_node->setNext(update[i]->getNext(i), i);
//         update[i]->setNext(new_node, i);
//     }
//     numberOfNodes++;
// }
