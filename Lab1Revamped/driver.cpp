#include <iostream>
#include "weightedMedian.h"

using namespace std;

int main()
{
    int numEntries = 10;
    int values[] = {1, 2, 3, 4, 5};
    float weights[] = {0.1, 0.2, 0.3, 0.4, 0.5};

    weightedMedianSolver solver = weightedMedianSolver();

    for (int i = 0; i < numEntries; i++)
    {
        solver.insert(values[i], weights[i]);
    }
    cout << "Median: " << solver.getMedian() << endl;
}