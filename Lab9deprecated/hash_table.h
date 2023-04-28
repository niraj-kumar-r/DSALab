#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <vector>
constexpr unsigned short THRESHOLD = 8;
#include "sq_table.h"

class hash_table
{
public:
  hash_table();
  void insert(int n);
  void Delete(int n);
  void print();

private:
  int hash(int n);
  void double_table();
  void halve_table();
  std::vector<sq_table> buckets_;
  int m_, c_;
  int num_elems_;
};

#endif // HASH_TABLE_H
