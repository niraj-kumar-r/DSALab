#include <bits/stdc++.h>
using namespace std;

void quicksort(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int smallPivot = a[l] <= a[r] ? a[l] : a[r];
    int largePivot = a[l] >= a[r] ? a[l] : a[r];
    int small = a[l] == smallPivot ? l : r;
    int large = a[r] == largePivot ? r : l;

    vector<int> less;
    vector<int> mid;
    vector<int> greater;

    for (int i = l; i <= r; i++)
    {
        if (a[i] < smallPivot)
        {
            less.push_back(a[i]);
        }
        else if (a[i] > smallPivot && a[i] < largePivot)
        {
            mid.push_back(a[i]);
        }
        else if (a[i] > largePivot)
        {
            greater.push_back(a[i]);
        }
        else
        {
            if (a[i] == smallPivot)
            {
                if (i < small)
                {
                    less.push_back(a[i]);
                }
                else if (i > small)
                {
                    mid.push_back(a[i]);
                }
            }
            else
            {
                if (i > large)
                {
                    greater.push_back(a[i]);
                }
                else if (i < large)
                {
                    mid.push_back(a[i]);
                }
            }
        }
    }
    for (int i = 0; i < less.size(); i++)
    {
        a[l + i] = less[i];
    }
    a[l + less.size()] = smallPivot;
    for (int i = 0; i < mid.size(); i++)
    {
        a[l + less.size() + 1 + i] = mid[i];
    }
    a[r - greater.size()] = largePivot;
    for (int i = 0; i < greater.size(); i++)
    {
        a[r - greater.size() + 1 + i] = greater[i];
    }

    quicksort(a, l, l + less.size() - 1);
    quicksort(a, l + less.size() + 1, r - greater.size() - 1);
    quicksort(a, r - greater.size() + 1, r);

    return;
}

// A utility function to print an array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

// Driver code
int main()
{
    int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    int size = sizeof(a) / sizeof(int);

    // Function Call
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
}
