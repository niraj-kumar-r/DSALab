#include <bits/stdc++.h>
using namespace std;

struct node_min
{
  char data;
  int fq;
  node_min *ltree, *rtree;
  node_min(char data, int fq)
  {
    this->data = data;
    this->fq = fq;
    ltree = NULL;
    rtree = NULL;
  }
};

struct compare
{
  bool operator()(node_min *l, node_min *r)
  {
    return (r->fq < l->fq);
  }
};

priority_queue<node_min *, vector<node_min *>, compare> minHeap;

void store_huff(struct node_min *root, string s);
// void Cal_fq_tree(string s, int n);
void Cal_fq_tree(string s);
void code_file(int size);
string Decode_file(struct node_min *root, string s);
