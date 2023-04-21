#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int l = left; l <= right; l++)
        arr[l] = temp[l - left];
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();

    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    vector<int> arr = {7, 2, 4, 1, 5, 3};
    mergeSort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
