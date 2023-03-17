int array[20] = {0};
int i = 0;
int fibs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n <= 1)
    {
        array[n - 1] = 1;
        return 1;
    }
    else
    {
        int out = fibs(n - 1) + fibs(n - 2);
        array[n - 1] = out;
        return out;
    }
}
int main()
{
    int n = 8;
    fibs(n);
}