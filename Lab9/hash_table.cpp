#include "hash_table.h"
#include <bits/stdc++.h>

using std::begin;
using std::end;
hash_table::hash_table() : num_elems_(1) {
  buckets_.resize(1);
  buckets_[0] = sq_table();
  m_=rand();
  c_=rand();
}

int hash_table::hash(int n) {
  if (num_elems_==1) return 0;
  return ((m_ * n + c_) % PRIME) % num_elems_;
}

void hash_table::insert(int n) {
  std::cout<<"Inserting "<<n<<std::endl;
  if (num_elems_==buckets_.size()) double_table();
  if (num_elems_==0){
    buckets_.resize(1);
    buckets_[0] = sq_table();
    buckets_[0].insert(n);
    num_elems_++;
    return;
  }
  if (num_elems_==1){
    if (n==buckets_[0].elems_[0]) return;
    buckets_.resize(2);
    buckets_[1] = sq_table();
    buckets_[1].insert(n);
    num_elems_++;
    return;
  }
  int i = hash(n);
  buckets_[i].insert(n);
}

void hash_table::Delete(int n) {
  if (num_elems_==0) return;
  if (num_elems_==1){
    if (n==buckets_[0].elems_[0]){
      buckets_[0].Delete(n);
      num_elems_--;
    }
    return;
  }
  int i = hash(n);
  buckets_[i].Delete(n);
  if (buckets_[i].num_elems_==0){
    buckets_[i]=buckets_[num_elems_-1];
    num_elems_--;
  }
}

void hash_table::print() {
  for (int i=0; i<num_elems_; i++){
    std::cout<<"Bucket "<<i<<": ";
    for (int j=0; j<buckets_[i].num_elems_; j++){
      std::cout<<buckets_[i].elems_[j]<<" ";
    }
    std::cout<<std::endl;
  }
}

void hash_table::double_table() {
  int old_num_elems = num_elems_;
  num_elems_*=2;
  buckets_.resize(num_elems_);
  for (int i=0; i<old_num_elems; i++){
    for (int j=0; j<buckets_[i].num_elems_; j++){
      int n = buckets_[i].elems_[j];
      int k = hash(n);
      if (k!=i){
        buckets_[k].insert(n);
        buckets_[i].Delete(n);
        j--;
      }
    }
  }
}

void hash_table::halve_table() {
  int old_num_elems = num_elems_;
  num_elems_/=2;
  buckets_.resize(num_elems_);
  for (int i=0; i<old_num_elems; i++){
    for (int j=0; j<buckets_[i].num_elems_; j++){
      int n = buckets_[i].elems_[j];
      int k = hash(n);
      if (k!=i){
        buckets_[k].insert(n);
        buckets_[i].Delete(n);
        j--;
      }
    }
  }
}

