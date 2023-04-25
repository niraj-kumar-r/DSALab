#include<iostream>
#include<vector>

using namespace std;
#define pi pair<int,float>

int partition(vector<pi> &v, int low, int high){
    int pivot= v[high].first;
    int i= low-1;
    for(int j=low; j<=high; j++){
        if(v[j].first<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}
void quickSort(vector<pi> &v, int low, int high){
    if(low<high){
        int i= partition(v,low,high);
        quickSort(v,low,i-1);
        quickSort(v,i+1,high);
    }
}

