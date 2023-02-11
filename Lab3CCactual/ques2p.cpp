int main()
{
    // swap by value

    int a = 5;
    int b = 10;
    a = a + b;
    b = a - b;
    a = a - b;

    // swap by address

    int *p = &a;
    int *q = &b;
    int temp = *p;
    *p = *q;
    *q = temp;
}