int myMul(int a, int b)
{
    return a * b;
}

int main()
{
    int req = 5;
    int result = 1;
    for (int i = 1; i <= req; i++)
    {
        result = myMul(result, i);
    }
}