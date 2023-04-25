#include <iostream>
#include <algorithm>

using namespace std;

int findAlphaQuantile(int data[], float weights[], int start, int end, float alpha);
int partition(int data[], float weights[], int left, int right);

int main()
{
    int A[] = {1, 3, 4, 9, 2, 7};
    float W[] = {0.1, 0.2, 0.1, 0.15, 0.05, 0.4};
    float alpha = 0;
    cout << "Enter alpha: ";
    cin >> alpha;
    cout << findAlphaQuantile(A, W, 0, (sizeof(A) / sizeof(int)) - 1, alpha) << endl;
}

int findAlphaQuantile(int data[], float weights[], int start, int end, float alpha)
{
    if (start > end)
    {
        return data[start];
    }
    int pivotIndex = medianOfMedians(data, start, end);
    pivotIndex = partition(data, weights, start, end, pivotIndex);
    float currentFx = 0;
    for (int i = 0; i <= pivotIndex; i++)
    {
        currentFx += weights[i];
    }
    if (currentFx > alpha)
    {
        return findAlphaQuantile(data, weights, start, pivotIndex - 1, alpha);
    }
    else
    {
        int nextMinIndex = pivotIndex + 1;
        for (int i = pivotIndex + 1; i <= end; i++)
        {
            if (data[i] < data[nextMinIndex])
            {
                nextMinIndex = i;
            }
        }
        if (currentFx + weights[nextMinIndex] > alpha)
        {
            return data[pivotIndex];
        }

        else
        {
            return findAlphaQuantile(data, weights, pivotIndex + 1, end, alpha);
        }
    }
}

// returns the index of median of medians
int medianOfMedians(int data[], int start, int end)
{
    int n = end - start + 1;
    int numGroups = n / 5;
    int medianIndices[numGroups];
    for (int i = 0; i < numGroups; i++)
    {
        int groupStart = start + i * 5;
        int groupEnd = groupStart + 4;
        medianIndices[i] = findMedian(data, groupStart, groupEnd);
    }
    int medianOfMediansIndex = findMedian(medianIndices, 0, numGroups - 1);
    return medianOfMediansIndex;
}

// returns the index of median
int findMedian(int data[], int start, int end)
{
    int n = end - start + 1;
    sort(data + start, data + end + 1);
    return start + n / 2;
}

int partition(int data[], float weights[], int left, int right, int pivotIndex)
{
    int pivot = data[pivotIndex];
    swap(data[pivotIndex], data[right]);
    swap(weights[pivotIndex], weights[right]);
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (data[j] < pivot)
        {
            swap(data[i], data[j]);
            swap(weights[i], weights[j]);
            i++;
        }
    }
    swap(data[i], data[right]);
    swap(weights[i], weights[right]);
    return i;
}