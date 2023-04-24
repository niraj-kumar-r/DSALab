#ifndef MYSKIPLISTS_H
#define MYSKIPLISTS_H
#include <vector>

class Node_t
{
private:
    int value;
    int max_level;

public:
    std::vector<Node_t *> next;
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
    void setHeight(int value);
    void setNumberOfNodes();
    Node_t *getNegInf();
    Node_t *getPosInf();
    std::vector<Node_t *> getPrevNodes(int value);
    Node_t *skipSearch(int value, int final_lvl = 0);
    void skipInsert(int value);
    void remove(int value);
    void print();
};

#endif