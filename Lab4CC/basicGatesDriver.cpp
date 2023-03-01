#include "basicGates.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
    {
        cout << "Usage: ./basicGatesDriver gate a b" << endl;
        return 1;
    }
    std::string gate = argv[1];
    Binary_t a(argv[2]);
    // Binary_t b(argv[3]);
    Binary_t b("1b0");
    if (argc == 4)
    {
        b = Binary_t(argv[3]);
    }
    BasicGates_t basicGates;
    Binary_t result;
    if (gate == "and")
    {
        result = basicGates.myAnd(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "or")
    {
        result = basicGates.myOr(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "not")
    {
        result = basicGates.myNot(a);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "nand")
    {
        result = basicGates.myNand(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "nor")
    {
        result = basicGates.myNor(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "xor")
    {
        result = basicGates.myXor(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else if (gate == "xnor")
    {
        result = basicGates.myXnor(a, b);
        cout << "output: " << result.getBinaryString() << endl;
        cout << "delay: " << basicGates.delay << endl;
    }
    else
    {
        cout << "Usage: ./basicGatesDriver gate a b" << endl;
        return 1;
    }
}