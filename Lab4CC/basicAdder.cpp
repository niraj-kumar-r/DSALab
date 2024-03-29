// Write a C/C++ code to design a simulator to simulate the functionality of half
// and full adder. The simulator should simulate the values in binary only. The input can be given in
// an user readable format such as in binary 1b0 and the output can be written
// out in the similar format.

#include <iostream>
#include "basicGates.h"
#include "basicAdder.h"

void BasicAdder_t::doHalfAddition(Binary_t a, Binary_t b)
{
    BasicGates_t basicGates;
    this->sum = basicGates.myXor(a, b);
    this->carry = basicGates.myAnd(a, b);
    this->delay = basicGates.delay;
}

void BasicAdder_t::doFullAddition(Binary_t a, Binary_t b, Binary_t c)
{
    BasicGates_t basicGates;
    this->sum = basicGates.myXor(basicGates.myXor(a, b), c);
    this->carry = basicGates.myOr(basicGates.myAnd(a, b), basicGates.myAnd(basicGates.myXor(a, b), c));
    this->delay = basicGates.delay;
}

void BasicAdder_t::doGenericRippleCarryAddition(Binary_t a, Binary_t b)
{

    BasicGates_t basicGates;
    Binary_t carry = basicGates.myAnd(a, b);
    Binary_t sum = basicGates.myXor(a, b);
    for (int i = 1; i < a.numBits; i++)
    {
        Binary_t aBit(a.value >> i, 1);
        Binary_t bBit(b.value >> i, 1);
        Binary_t carryBit(carry.value >> i, 1);
        Binary_t sumBit(sum.value >> i, 1);
        BasicAdder_t fullAdder;
        fullAdder.doFullAddition(aBit, bBit, carryBit);
        carry.value = carry.value | (fullAdder.carry.value << i);
        sum.value = sum.value | (fullAdder.sum.value << i);
    }
    this->carry = carry;
    this->sum = sum;

    int fullAdderDelay = 0;
    BasicAdder_t fullAdder;
    fullAdder.doFullAddition(Binary_t("1b0"), Binary_t("1b0"), Binary_t("1b0"));
    fullAdderDelay = fullAdder.delay;

    this->delay = fullAdderDelay * (a.numBits - 1) + 1;
}

void BasicAdder_t::doGenericCarryLookAheadAddition(Binary_t a, Binary_t b)
{
    BasicGates_t basicGates;
    basicGates.myAnd(Binary_t("1b0"), Binary_t("1b0"));

    int andDelay = basicGates.delay;
    basicGates.delay = 0;
    basicGates.myOr(Binary_t("1b0"), Binary_t("1b0"));
    int orDelay = basicGates.delay;
    basicGates.delay = 0;

    Binary_t carry = basicGates.myAnd(a, b);
    Binary_t sum = basicGates.myXor(a, b);
    for (int i = 1; i < a.numBits; i++)
    {
        Binary_t aBit(a.value >> i, 1);
        Binary_t bBit(b.value >> i, 1);
        Binary_t carryBit(carry.value >> i, 1);
        Binary_t sumBit(sum.value >> i, 1);
        BasicAdder_t halfAdder;
        halfAdder.doHalfAddition(aBit, bBit);
        BasicAdder_t fullAdder;
        fullAdder.doFullAddition(halfAdder.sum, carryBit, basicGates.myAnd(halfAdder.carry, carryBit));
        carry.value = carry.value | (fullAdder.carry.value << i);
        sum.value = sum.value | (fullAdder.sum.value << i);
    }
    this->carry = carry;
    this->sum = sum;
    basicGates.delay = 0;
    this->delay = andDelay + orDelay + basicGates.delay;
}
