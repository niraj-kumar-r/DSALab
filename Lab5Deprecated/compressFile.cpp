#include "huffmanCoding.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return 1;
    }
    HuffmanCoding_t huffman;
    huffman.compress(argv[1], argv[2]);
    cout << "Compression complete" << endl;
    return 0;
}