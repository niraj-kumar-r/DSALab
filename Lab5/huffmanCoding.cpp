#include "huffmanCoding.h"
#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// huftree class

// Constructor
HuffmanCoding_t::HuffmanCoding_t()
{
    root = NULL;
}

// Building huffman tree for possiblities a-z and space
void HuffmanCoding_t::buildHuffmanTree(std::string text, bool writeFile = false, std::string fileName = "")
{
    int freq[27] = {0};
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            freq[26]++;
        }
        else
        {
            freq[text[i] - 'a']++;
        }
    }
    if (writeFile)
    {
        // write the frequency of each character to a file
        ofstream file(fileName);
        if (file.is_open())
        {
            for (int i = 0; i < 27; i++)
            {
                file << freq[i];
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file";
        }
    }
    for (int i = 0; i < 27; i++)
    {
        if (freq[i] != 0)
        {
            minHeap.push(Node_t('a' + i, freq[i]));
        }
    }
    while (minHeap.size() != 1)
    {
        Node_t left = minHeap.top();
        minHeap.pop();
        Node_t right = minHeap.top();
        minHeap.pop();
        Node_t top('\0', left.freq + right.freq);
        top.left = new Node_t(left);
        top.right = new Node_t(right);
        minHeap.push(top);
    }
    root = new Node_t(minHeap.top());
}

// Building huffman tree from txt file
void HuffmanCoding_t::buildHuffmanTreeFromTxtFile(std::string inputFileName, bool writeFile = false, std::string outputFileName = "")
{
    string text;
    ifstream file(inputFileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            text += line;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    buildHuffmanTree(text, writeFile, outputFileName);
}

// Building code map

void HuffmanCoding_t::buildCodeMap(Node_t *root, long code, int top)
{
    if (root->left)
    {
        buildCodeMap(root->left, code << 1, top + 1);
    }
    if (root->right)
    {
        buildCodeMap(root->right, (code << 1) + 1, top + 1);
    }
    if (!root->left && !root->right)
    {
        codemap_t temp;
        temp.code = code;
        temp.numBits = top;
        codeMap[root->data] = temp;
    }
}

void HuffmanCoding_t::compress(std::string inputFileName, std::string outputFileName)
{
    // read the text from the input file
    buildHuffmanTreeFromTxtFile(inputFileName, true, outputFileName);
    // build the code map
    buildCodeMap(root, 0, 0);
    // write the compressed text to the output file
    ofstream outFile(outputFileName, ios::app | ios::binary);
    ifstream inFile(inputFileName);
    if (inFile.is_open() && outFile.is_open())
    {
        unsigned long encodedText = 0;
        int size = 0;
        int rembits = sizeof(unsigned long) * 8;
        char c;
        while (!inFile.eof())
        {
            inFile.get(c);
            rembits = sizeof(unsigned long) * 8 - size;
            if (rembits >= codeMap[c].numBits)
            {
                encodedText = encodedText << codeMap[c].numBits;
                encodedText = encodedText | codeMap[c].code;
                size += codeMap[c].numBits;
            }
            else if (rembits > 0)
            {
                encodedText = encodedText << rembits;
                encodedText = encodedText | (codeMap[c].code >> (codeMap[c].numBits - rembits));
                outFile.write((char *)&encodedText, sizeof(unsigned long));
                encodedText = 0;
                encodedText = encodedText | (codeMap[c].code << (sizeof(unsigned long) * 8 - (codeMap[c].numBits - rembits)));
                size = codeMap[c].numBits - rembits;
            }
            else
            {
                outFile.write((char *)&encodedText, sizeof(unsigned long));
                encodedText = 0;
                encodedText = encodedText | codeMap[c].code;
                size = codeMap[c].numBits;
            }
        }
        if (size != 0)
        {
            encodedText = encodedText << (sizeof(unsigned long) * 8 - size);
            outFile.write((char *)&encodedText, sizeof(unsigned long));
        }
    }
    else
    {
        cout << "Unable to open file";
    }
}