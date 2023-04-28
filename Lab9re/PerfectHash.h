#ifndef PERFECT_HASH_H
#define PERFECT_HASH_H

// dynamic perfect hashing implemented as a table of tables

constexpr int MIN_THRESHOLD = 4;
constexpr float c_global = 0.5;

constexpr unsigned int PRIME = 19937;

#include <vector>

class InnerTable
{
public:
    InnerTable();
    std::vector<std::pair<int, bool>> elems_;
    int bj, mj, sj;

    int hash(int n);
    void setNewHash();
    void rehashInner(int elem = -1, bool toInsert = false);

private:
    int a_, b_;
};

class HashTable
{
public:
    HashTable();
    void insertElement(int x);
    void deleteElement(int x);
    bool findElement(int x);
    void print();

private:
    std::vector<InnerTable> buckets_;
    int a_main_, b_main_, num_elems_, M, sM, count;

    int hash_main(int n);
    void setNewHash();
    void rehashAll(int elem = -1, bool toInsert = false);
    bool starStarSatisfied();
};

#endif
