#ifndef PERFECT_HASH_H
#define PERFECT_HASH_H
// dynamic perfect hashing implemented as a table of tables

constexpr int MIN_THRESHOLD = 4;
constexpr float c_global = 0.5;

constexpr unsigned int PRIME = 19937;
// constexpr int RESERVED = 0;
#include <vector>

class InnerTable
{
public:
    InnerTable();
    // void insertElement(int n);
    // void deleteElement(int n);
    // void clearTable();
    // int num_elems_;
    std::vector<std::pair<int, bool>> elems_;
    // bool can be set to false to delete an element, that is
    // use as valid bit
    int bj, mj, sj;
    void setNewHash();
    void rehashInner(int elem = -1, bool toInsert = false);
    int hash(int n);

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
    int hash_main(int n);
    void setNewHash();
    void rehashAll(int elem = -1, bool toInsert = false);
    bool starStarSatisfied();
    // void double_table();
    // void halve_table();
    std::vector<InnerTable> buckets_;
    int a_main_, b_main_;
    int num_elems_;
    int M;
    int sM;
    int count;
};

#endif
