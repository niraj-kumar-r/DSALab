#include "basicGates.h"
#include <iostream>
#include <string>
#include <bitset>

Binary_t::Binary_t()
{
    value = 0;
    numBits = 0;
    binaryString = "";
}

Binary_t::Binary_t(std::string inputString)
{
    int i = 0;
    while (inputString[i] != 'b')
    {
        i++;
    }
    this->binaryString = inputString.substr(i + 1);
    this->numBits = binaryString.length();
    this->value = stoi(binaryString, nullptr, 2);
}

Binary_t::Binary_t(int value, int numBits)
{
    this->value = value;
    this->numBits = numBits;
    this->binaryString = std::bitset<32>(value).to_string();
    this->binaryString = this->binaryString.substr(32 - numBits);
}

std::string Binary_t::getBinaryString()
{
    return (std::to_string(numBits) + "b" + this->binaryString);
}

Binary_t BasicGates_t::myAnd(Binary_t a, Binary_t b, int gateDelay)
{
    int value = a.value & b.value;
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myOr(Binary_t a, Binary_t b, int gateDelay)
{
    int value = a.value | b.value;
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myNot(Binary_t a, int gateDelay)
{
    int value = ~a.value;
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myNand(Binary_t a, Binary_t b, int gateDelay)
{
    int value = ~(a.value & b.value);
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myNor(Binary_t a, Binary_t b, int gateDelay)
{
    int value = ~(a.value | b.value);
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myXor(Binary_t a, Binary_t b, int gateDelay)
{
    int value = a.value ^ b.value;
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}

Binary_t BasicGates_t::myXnor(Binary_t a, Binary_t b, int gateDelay)
{
    int value = ~(a.value ^ b.value);
    int numBits = a.numBits;
    Binary_t result(value, numBits);
    delay += gateDelay;
    return result;
}
