#include "generalizedStack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

stack_t::stack_t(STYPE_T type)
{
    TYPE = type;
    head = -1;
}

element_t stack_t::peek()
{
    if (isEmpty())
    {
        throw invalid_argument("Stack is empty");
    }
    return arr[head];
}

element_t stack_t::pop()
{
    if (head == 0)
    {
        head = -1;
        return arr[0];
    }
    else if (head == -1)
    {
        throw invalid_argument("Stack is empty");
    }
    else
    {
        head--;
        return arr[head + 1];
    }
}

bool stack_t::isFull()
{
    return head >= STACK_SIZE - 1;
}

bool stack_t::isEmpty()
{
    return head == -1;
}

void stack_t::push(int a)
{
    if (TYPE != STYPE_INT)
    {
        throw invalid_argument("Only ints can be passed as arguments");
    }
    else
    {
        if (isFull())
        {
            throw invalid_argument("Stack Overflow");
        }
        else
        {
            head++;
            arr[head].x = a;
        }
    }
}

void stack_t::push(char a)
{
    if (TYPE != STYPE_CHAR)
    {
        throw invalid_argument("Only ints can be passed as arguments");
    }
    else
    {
        if (isFull())
        {
            throw invalid_argument("Stack Overflow");
        }
        else
        {
            head++;
            arr[head].y = a;
        }
    }
}

void stack_t::push(float a)
{
    if (TYPE != STYPE_FLOAT)
    {
        throw invalid_argument("Only ints can be passed as arguments");
    }
    else
    {
        if (isFull())
        {
            throw invalid_argument("Stack Overflow");
        }
        else
        {
            head++;
            arr[head].z = a;
        }
    }
}

void stack_t::push(int *a)
{
    if (TYPE != STYPE_PTR)
    {
        throw invalid_argument("Only ints can be passed as arguments");
    }
    else
    {
        if (isFull())
        {
            throw invalid_argument("Stack Overflow");
        }
        else
        {
            head++;
            arr[head].p = a;
        }
    }
}

void stack_t::setType(STYPE_T type)
{
    TYPE = type;
}

int getInt(element_t a)
{
    return a.x;
}

char getChar(element_t a)
{
    return a.y;
}

float getFloat(element_t a)
{
    return a.z;
}

int *getPtr(element_t a)
{
    return a.p;
}
