#ifndef HUFFMAN_IO_H
#define HUFFMAN_IO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include "huffman.h"
using std::cout, std::cin, std::string, std::stringstream, std::ifstream, std::ofstream, std::bitset;

void write(string bstr, ofstream &fptr);
void write();
string read(const string &fname);
#endif // HUFFMAN_IO_H
