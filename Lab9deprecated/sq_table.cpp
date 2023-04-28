#include "sq_table.h"

#include <bits/stdc++.h>

sq_table::sq_table()
{
  num_elems_ = 0;
}

int sq_table::hash(int n)
{
  if (num_elems_ == 1 or num_elems_ == 0)
  {
    return 0;
  }
  return ((m_ * n + c_) % PRIME) % (num_elems_ * num_elems_);
}

void sq_table::insert(int n)
{
  if (num_elems_ == 0)
  {
    elems_.push_back(n);
    num_elems_++;
    return;
  }
  if (num_elems_ == 1)
  {
    if (n == elems_[0])
    {
      return;
    }
    elems_.push_back(n);
    num_elems_++;
    return;
  }
  int i = hash(n);
  if (elems_[i] == RESERVED)
  {
    elems_[i] = n;
    num_elems_++;
    return;
  }
  if (elems_[i] == n)
    return;
  int temp = elems_[i];
  elems_[i] = n;
  insert(temp);
}

void sq_table::Delete(int n)
{
  if (num_elems_ == 0)
    return;
  if (num_elems_ == 1)
  {
    if (n == elems_[0])
    {
      elems_.pop_back();
      num_elems_--;
    }
    return;
  }
  int i = hash(n);
  if (elems_[i] == n)
  {
    elems_[i] = RESERVED;
    num_elems_--;
  }
}
