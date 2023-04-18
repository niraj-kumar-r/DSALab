#ifndef GENERALIZEDSTACK_H
#define GENERALIZEDSTACK_H

#define STACK_SIZE 1000

typedef union
{
    int x;
    char y;
    float z;
    int *p;
} element_t;

int getInt(element_t a);
char getChar(element_t a);
float getFloat(element_t a);
int *getPtr(element_t a);

typedef enum
{
    STYPE_INT,
    STYPE_CHAR,
    STYPE_FLOAT,
    STYPE_PTR,
} STYPE_T;

class stack_t
{
private:
    element_t arr[STACK_SIZE];
    int head;
    STYPE_T TYPE;

public:
    stack_t(STYPE_T type);
    void push(int a);
    void push(char a);
    void push(float a);
    void push(int *a);
    element_t pop();
    element_t peek();
    bool isEmpty();
    bool isFull();
    void setType(STYPE_T type);
};

#endif