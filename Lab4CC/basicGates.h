#ifndef BASICGATES_H
#define BASICGATES_H

#include <iostream>
#include <string>

#define AND_DELAY 1
#define OR_DELAY 1
#define NOT_DELAY 1
#define NAND_DELAY 1
#define NOR_DELAY 1
#define XOR_DELAY 1
#define XNOR_DELAY 1

class Binary_t
{
public:
    int value;
    int numBits;
    std::string binaryString;
    Binary_t();
    Binary_t(std::string inputString);
    Binary_t(int value, int numBits);
    std::string getBinaryString();
};

class BasicGates_t
{

public:
    int delay = 0;
    Binary_t myAnd(Binary_t a, Binary_t b, int gateDelay = AND_DELAY);
    Binary_t myOr(Binary_t a, Binary_t b, int gateDelay = OR_DELAY);
    Binary_t myNot(Binary_t a, int gateDelay = NOT_DELAY);
    Binary_t myNand(Binary_t a, Binary_t b, int gateDelay = NAND_DELAY);
    Binary_t myNor(Binary_t a, Binary_t b, int gateDelay = NOR_DELAY);
    Binary_t myXor(Binary_t a, Binary_t b, int gateDelay = XOR_DELAY);
    Binary_t myXnor(Binary_t a, Binary_t b, int gateDelay = XNOR_DELAY);
};

#endif