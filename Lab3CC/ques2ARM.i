# 0 "ques2.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "ques2.c"
int main()
{
    double arr2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    double arr3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    double arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 9; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
    return 0;
}
