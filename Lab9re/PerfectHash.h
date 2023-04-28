#ifndef PERFECT_HASH_H
#define PERFECT_HASH_H
// dynamic perfect hashing implemented as a table of tables

constexpr unsigned short MIN_THRESHOLD = 8;

constexpr unsigned int PRIME = 19937;
// constexpr int RESERVED = 0;
#include <vector>

class InnerTable
{
public:
    InnerTable();
    void insertElement(int n);
    void deleteElement(int n);
    int num_elems_;
    std::vector<std::pair<int, bool>> elems_;
    // bool can be set to false to delete an element, taht is
    // use as valid bit

private:
    int hash(int n);
    void setNewHash();
    void rehashAll();
    int a_, b_;
};

class HashTable
{
public:
    HashTable();
    void insertElement(int n);
    void deleteElement(int n);
    void print();

private:
    int hash(int n);
    void setNewHash();
    void double_table();
    void halve_table();
    std::vector<InnerTable> buckets_;
    int a_main_, b_main_;
    int num_elems_;
};

#endif
