#include <iostream>
#include "generalizedStack.h"
using namespace std;

int main()
{
    stack_t STK(STYPE_CHAR);
    STK.push('a');
    STK.push('n');
    cout << getChar(STK.peek()) << '\n';
    cout << getChar(STK.pop()) << '\n';
    cout << getChar(STK.peek()) << '\n';
    cout << getChar(STK.pop()) << '\n';

    STK.setType(STYPE_INT);

    STK.push(23);
    STK.push(87);
    cout << getInt(STK.peek()) << '\n';
    cout << getInt(STK.pop()) << '\n';
    cout << getInt(STK.peek()) << '\n';
    cout << getInt(STK.pop()) << '\n';
    cout << getInt(STK.pop()) << '\n';
}