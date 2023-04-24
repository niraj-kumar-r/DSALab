#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node *l, Node *r)
    {
        // The highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

Node *buildHuffmanTree(string text);

void generateHuffmanCodes(Node *root, string code, unordered_map<char, string> &codeTable);

string encode(string text, unordered_map<char, string> &codeTable);

string decode(std::string code, Node *root);

long long fileSize(string filename);

#endif