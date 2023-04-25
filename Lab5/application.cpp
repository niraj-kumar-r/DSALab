#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>
#include "huffman.h"

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    string text((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    Node *root = buildHuffmanTree(text);
    unordered_map<char, string> codeTable;
    generateHuffmanCodes(root, "", codeTable);

    cout << "The codes are: " << endl;
    for (auto str : codeTable)
    {
        cout << str.first << ": " << str.second << endl;
    }

    string encoded = encode(text, codeTable);
    cout << "The encoded string is: " << encoded << endl;

    ofstream outputFile("encoded.bin", ios::binary);
    int numBytes = encoded.length() / 8;
    for (size_t i = 0; i < encoded.length(); i += 8)
    {
        uint8_t byte = 0;
        for (size_t j = 0; j < 8 && i + j < encoded.length(); j++)
        {
            byte = byte << 1 | (encoded[i + j] == '1' ? 1 : 0);
        }
        outputFile.write(reinterpret_cast<char *>(&byte), 1);
    }
    outputFile.close();

    long long inputFileSize = fileSize("input.txt");
    long long encodedFileSize = fileSize("encoded.bin");
    cout << "Size of input file: " << inputFileSize << " bytes" << endl;
    cout << "Size of encoded file: " << encodedFileSize << " bytes" << endl;
    cout << "Compression ratio: " << (double)encodedFileSize / inputFileSize << endl;
    inputFile.close();

    inputFile.open("encoded.bin", ios::binary);
    int n = encoded.length();
    char s[(n + 7) / 8];
    inputFile.read(s, (n + 7) / 8);
    string rencoded;
    int i = 0;
    for (char ch : s)
    {
        std::bitset<8> b(ch);
        rencoded += b.to_string();
    }
    inputFile.close();
    int actual_bits = encoded.length() % 8;
    if (actual_bits != 0)
    {
        int reduced_length = (n / 8) * 8;
        rencoded = rencoded.substr(0, reduced_length) + rencoded.substr(reduced_length + 8 - actual_bits);
    }
    ofstream output_file("decoded.txt");
    string decoded = decode(rencoded, root);

    cout << "Output string is: " << decoded << endl;
    output_file << decoded;
    output_file.close();

    delete root;

    return 0;
}
