#ifndef MYSKIPLISTS_H
#define MYSKIPLISTS_H
#include <vector>

class Node_t
{
private:
    int value;
    int max_level;
    vector<Node_t *> next;

public:
    Node_t();
    Node_t(int value);
    int getValue();
    int getMaxLevel();
    Node_t *getNext(int level);
    void setValue(int value);
    void setMaxLevel(int max_level);
    void setNext(Node_t *next, int level);
};

class SkipList_t
{

private:
    Node_t *neg_inf;
    Node_t *pos_inf;
    int height;
    int numberOfNodes;

public:
    SkipList_t();
    int getHeight();
    int getNumberOfNodes();
    Node_t *getNegInf();
    Node_t *getPosInf();
    void insert(int value);
    Node_t *search(int value);
    void remove(int value);
};

#endif