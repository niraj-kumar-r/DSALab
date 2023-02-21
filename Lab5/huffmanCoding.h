#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H
#include <iostream>
#include <queue>
#include <string>
#include <map>

struct Node_t
{
    char data;
    int freq;
    Node_t *left, *right;
    Node_t(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
    bool operator<(const Node_t &other) const
    {
        return freq > other.freq;
    }
    bool operator>(const Node_t &other) const
    {
        return freq < other.freq;
    }
};

struct codemap_t
{
    long code;
    unsigned int numBits;
};

class HuffmanCoding_t
{
private:
    std::priority_queue<Node_t, std::vector<Node_t>, std::greater<Node_t>> minHeap;
    Node_t *root;
    std::map<char, codemap_t> codeMap;
    void buildHuffmanTree(std::string text, bool writeFile = false, std::string fileName = "");
    void buildHuffmanTreeFromTxtFile(std::string inputFileName, bool writeFile = false, std::string outputFileName = "");
    void buildCodeMap(Node_t *root, long code, int top);

public:
    HuffmanCoding_t();
    void compress(std::string inputFileName, std::string outputFileName);
    void decompress(std::string inputFileName, std::string outputFileName);
};

#endif