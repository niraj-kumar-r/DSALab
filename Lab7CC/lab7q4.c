int fib(int a, int b, int req)
{
    if (b > req)
    {
        return a;
    }
    else
    {
        return fib(b, a + b, req);
    }
}

int main()
{
    int req = 20;
    int result = fib(1, 1, req);
}