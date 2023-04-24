#ifndef PERFECT_HASHING_H
#define PERFECT_HASHING_H

#include <vector>

// does dynamic perfect hashing with the secondary container only having one element
class PerfectHash
{
public:
    PerfectHash();
    void insert(int key);
    void print();

private:
    std::vector<int> keys;
};
#endif