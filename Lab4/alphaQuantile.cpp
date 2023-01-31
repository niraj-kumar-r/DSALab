#include <iostream>

using namespace std;

int findAlphaQuantile(int data[], float weights[], int start, int end, float alpha, float *presentFx);
int partition(int data[], float weights[], int left, int right, float *presentFx);

int main()
{
    int A[] = {1, 3, 4, 9, 2, 7};
    float W[] = {0.1, 0.2, 0.1, 0.15, 0.05, 0.4};
    float alpha = 0.3;
    float presentFx = 0;
    cout << findAlphaQuantile(A, W, 0, sizeof(A) - 1, alpha, &presentFx) << endl;
}

int findAlphaQuantile(int data[], float weights[], int start, int end, float alpha, float *presentFx)
{
    if (start == end)
    {
        return data[start];
    }
    int prevFx = *presentFx;
    int pivotIndex = partition(data, weights, start, end, presentFx);
    if (*presentFx == alpha)
    {
        return data[pivotIndex];
    }
    else if (*presentFx > alpha)
    {
        *presentFx = prevFx;
        return findAlphaQuantile(data, weights, start, pivotIndex - 1, alpha, presentFx);
    }
    else
    {
        return findAlphaQuantile(data, weights, pivotIndex + 1, end, alpha, presentFx);
    }
}

int partition(int data[], float weights[], int left, int right, float *presentFx)
{
    int pivot = data[right];
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (data[j] < pivot)
        {
            swap(data[i], data[j]);
            swap(weights[i], weights[j]);
            *presentFx += weights[i];
            i++;
        }
    }
    swap(data[i], data[right]);
    swap(weights[i], weights[right]);
    *presentFx += weights[i];
    return i;
}