#include <iostream>
#include <vector>
using namespace std;

class KaryMaxHeap
{
private:
    vector<int> heap;
    int k;

public:
    KaryMaxHeap(int k)
    {
        this->k = k;
    }

    void insert(int val)
    {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0)
        {
            int parent = (i - 1) / k;
            if (heap[parent] < heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    int extractMax()
    {
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0;
        while (true)
        {
            int child = k * i + 1;
            if (child >= heap.size())
            {
                break;
            }
            int maxChild = child;
            for (int j = 1; j < k && child + j < heap.size(); j++)
            {
                if (heap[child + j] > heap[maxChild])
                {
                    maxChild = child + j;
                }
            }
            if (heap[maxChild] > heap[i])
            {
                swap(heap[maxChild], heap[i]);
                i = maxChild;
            }
            else
            {
                break;
            }
        }
        return max;
    }
};

int main()
{
    KaryMaxHeap heap(3);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(10);
    heap.insert(7);

    cout << heap.extractMax() << endl; // 10
    cout << heap.extractMax() << endl; // 8
    cout << heap.extractMax() << endl; // 7
    cout << heap.extractMax() << endl; // 5
    cout << heap.extractMax() << endl; // 3
    cout << heap.extractMax() << endl; // 1

    return 0;
}
