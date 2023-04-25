#include <iostream>
#include <vector>
#include <climits>
#define pi pair<int, float>
#include "QuickSort.cpp"
using namespace std;

float round(float var)
{
    float val = (int)(var * 100 + .5);
    return (float)val / 100;
}

int medianOfMedian(vector<pi> v)
{
    while (v.size() % 5 != 0)
        v.push_back({INT_MAX, 0});
    if (v.size() <= 5)
    {
        quickSort(v, 0, v.size() - 1);
        return v[2].first;
    }
    vector<pi> temp;
    vector<pi> medians;
    for (int i = 0; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        if ((i + 1) % 5 == 0)
        {
            quickSort(temp, 0, temp.size() - 1);
            medians.push_back(temp[2]);
            temp.clear();
        }
    }
    return medianOfMedian(medians);
}
int partition2(vector<pi> &v, int low, int high)
{
    int i = low - 1;
    int pivot = medianOfMedian(vector<pi>(v.begin() + low, v.begin() + high + 1));
    if (pivot == INT_MAX)
        pivot = v[high].first;
    int pivIn = 0;
    for (int j = low; j <= high; j++)
    {
        if (v[j].first < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    for (int i = low; i <= high; i++)
    {
        if (v[i].first == pivot)
        {
            pivIn = i;
            break;
        }
    }
    swap(v[pivIn], v[i + 1]);
    return i + 1;
}
int select(vector<pair<int, float>> &v, int low, int high, float alpha)
{
    int k = partition2(v, low, high);
    float s = 0;
    for (int i = low; i < k; i++)
    {
        s += v[i].second;
    }
    int minVal = v[k + 1].first, minIdx = k + 1;
    for (int i = k + 1; i <= high; i++)
    {
        if (v[i].first < minVal)
        {
            minVal = v[i].first;
            minIdx = i;
        }
    }
    float temp = s + v[k].second + v[minIdx].second;
    if (s <= alpha)
    {
        if (int(round(v[k].second + s) * 10000) > int(round(alpha) * 10000))
        {
            int maxVal = v[low].first, maxIdx = low;
            for (int i = low; i < k; i++)
            {
                if (v[i].first > maxVal)
                {
                    maxVal = v[i].first;
                    maxIdx = i;
                }
            }
            return maxIdx;
        }
        else if (int(round(temp) * 10000) > int(round(alpha) * 10000))
        {
            return k;
        }
        else
            return select(v, k + 1, high, alpha - s - v[k].second);
    }
    return select(v, 0, k - 1, alpha);
}

int main()
{
    cout << "Enter the number of elements: " << endl;
    int n;
    cin >> n;

    cout << "Enter the elements with their probabilities : " << endl;
    vector<pair<int, float>> v(n);
    int weightSum = 0;
    int maxVal = INT_MIN;
    int maxIdx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        weightSum += v[i].second;
        if (v[i].first > maxVal)
        {
            maxVal = v[i].first;
            maxIdx = i;
        }
    }

    cout << "Enter the value of alpha: " << endl;
    float alpha = 0;
    cin >> alpha;
    cout << "The alpha quantile is: " << endl;
    if (alpha <= 0)
    {
        cout << v[0].first << endl;
        return 0;
    }
    if (alpha >= weightSum)
    {
        cout << v[maxIdx].first << endl;
        return 0;
    }
    int ans = select(v, 0, n - 1, alpha);
    cout << v[ans].first << endl;
    return 0;
}