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
    if (level > this->max_level)
    {
        this->setMaxLevel(level);
        this->next.resize(level, nullptr);
    }
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

// Set height
void SkipList_t::setHeight(int value)
{
    height = value;
}

// Set number of nodes
void SkipList_t::setNumberOfNodes()
{
    numberOfNodes++;
}

Node_t *SkipList_t::skipSearch(int value, int final_lvl = 0)
{
    Node_t *current = getNegInf();
    int current_lvl = current->getMaxLevel();
    while (current_lvl >= final_lvl)
    {
        current_lvl--;
        while (current->getNext(current_lvl)->getValue() < value)
        {
            current = current->getNext(current_lvl);
        }
    }
    return current;
}

vector<Node_t *> SkipList_t::getPrevNodes(int value)
{
    vector<Node_t *> prev_nodes;
    prev_nodes.resize(getHeight() + 1, neg_inf);

    Node_t *current = getNegInf();
    int current_lvl = current->getMaxLevel();
    while (current_lvl >= 0)
    {
        current_lvl--;
        while (current->getNext(current_lvl)->getValue() < value)
        {
            current = current->getNext(current_lvl);
        }
        prev_nodes[current_lvl] = current;
    }
    return prev_nodes;
}

void SkipList_t::skipInsert(int value)
{
    Node_t *new_node = new Node_t(value);
    vector<Node_t *> prev_nodes = getPrevNodes(value);

    int current_lvl = -1;
    Node_t *current = nullptr;
    do
    {
        current_lvl++;
        current = prev_nodes[current_lvl];
        if (current_lvl >= getHeight())
        {
            setHeight(getHeight() + 1);
            pos_inf->setNext(nullptr, getHeight());
            neg_inf->setNext(pos_inf, getHeight());
        }
        new_node->setNext(current->getNext(current_lvl), current_lvl);
        current->setNext(new_node, current_lvl);
    } while (rand() % 2 == 0);
    numberOfNodes++;
}

void SkipList_t::remove(int value)
{
    Node_t *current = skipSearch(value);
    if (current->getValue() != value)
    {
        return;
    }
    vector<Node_t *> prev_nodes = getPrevNodes(value);
    for (int i = 0, n = current->getMaxLevel(); i <= n; i++)
    {
        prev_nodes[i]->setNext(current->getNext(i), i);
    }
    delete current;
}