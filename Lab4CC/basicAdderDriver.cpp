#include <iostream>
#include "basicAdder.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
    {
        cout << "Usage: ./basicAdderDriver adder a b" << endl;
        return 1;
    }
    std::string adder = argv[1];
    Binary_t a(argv[2]);
    Binary_t b(argv[3]);
    BasicAdder_t basicAdder;
    if (adder == "halfAdder")
    {
        basicAdder.doHalfAddition(a, b);
        cout << "sum: " << basicAdder.sum.getBinaryString() << endl;
        cout << "carry: " << basicAdder.carry.getBinaryString() << endl;
        cout << "delay: " << basicAdder.delay << endl;
    }
    else if (adder == "fullAdder")
    {
        basicAdder.doFullAddition(a, b);
        cout << "sum: " << basicAdder.sum.getBinaryString() << endl;
        cout << "carry: " << basicAdder.carry.getBinaryString() << endl;
        cout << "delay: " << basicAdder.delay << endl;
    }
    else if (adder == "rippleCarryAdder")
    {
        basicAdder.doGenericRippleCarryAddition(a, b);
        cout << "sum: " << basicAdder.sum.getBinaryString() << endl;
        cout << "carry: " << basicAdder.carry.getBinaryString() << endl;
        cout << "delay: " << basicAdder.delay << endl;
    }
    else if (adder == "carryLookAheadAdder")
    {
        basicAdder.doGenericCarryLookAheadAddition(a, b);
        cout << "sum: " << basicAdder.sum.getBinaryString() << endl;
        cout << "carry: " << basicAdder.carry.getBinaryString() << endl;
        cout << "delay: " << basicAdder.delay << endl;
    }
    else
    {
        cout << "Usage: ./basicAdderDriver adder a b" << endl;
        return 1;
    }
}