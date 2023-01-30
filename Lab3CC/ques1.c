int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int arr3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
    return 0;
}