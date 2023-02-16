#ifndef BASICADDER_H
#define BASICADDER_H

#include <iostream>
#include "basicGates.h"

class BasicAdder_t
{
public:
    Binary_t sum;
    Binary_t carry;
    int delay = 0;
    void setDelay(int d);
    void doHalfAddition(Binary_t a, Binary_t b);
    void doFullAddition(Binary_t a, Binary_t b, Binary_t c = Binary_t(0, 1));
    void doGenericRippleCarryAddition(Binary_t a, Binary_t b);
    void doGenericCarryLookAheadAddition(Binary_t a, Binary_t b);
};

#endif