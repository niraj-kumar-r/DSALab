#ifndef SQ_TABLE_H
#define SQ_TABLE_H

constexpr unsigned int PRIME = 19937;
constexpr int RESERVED = 0;
#include <vector>

class sq_table
{
public:
  sq_table();
  void insert(int n);
  void Delete(int n);
  int num_elems_;
  std::vector<int> elems_;

private:
  int hash(int n);
  int m_, c_;
};

#endif // SQ_TABLE_H
