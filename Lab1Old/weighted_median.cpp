#include <bits/stdc++.h>
using namespace  std;

vector<int> mHeap;
vector<int> MHeap;

int wght[1000] = {0};

int parent(int x ){
 return (x-1)/2;
}
int leftT(int x){
    return 2*x+1;
}
int rightT(int x){
    return 2*x+2;
}

void max_heapifyup(vector<int> &vec, int x){
    if (x==0)
     return;
    
    if(vec[x]>vec[parent(x)]){
      swap(vec[parent(x)], vec[x]);
      max_heapifyup(vec, parent(x));
    }
}

void min_heapifyup(vector<int> &vec, int x){
    if (x==0)
     return;
    
    if(vec[x]<vec[parent(x)]){
      swap(vec[parent(x)], vec[x]);
      min_heapifyup(vec, parent(x));
    }
}

void max_heapifydwn(vector<int> &vec, int x ){
    int left = leftT(x);
    int right = rightT(x);
    int largest =x;

    if( left< vec.size() && vec[left]> vec[x])
        largest = left;
    
    if( vec[largest] < vec[right] && right<vec.size())
      largest = right;

    if (largest!=x ){
        swap(vec[x], vec[largest]);
        max_heapifydwn(vec,largest);
    }
}

void delete_heap(vector<int> &term, int x)
{int temp= term[x];
    term[x]=term [term.size()-1];
    term [term.size()-1]=temp;
    auto it = term.begin();
    term.erase(it+ term.size()-1);
    if(term[x]>=term[parent(x)]){
        max_heapifyup(term,x);
    }
    else{
        max_heapifydwn(term,x);
    }}

int main(){

  int t, w;
  cin>>t>>w;
  vector<int> term;
  term.push_back(t);
  wght[t] += w;

  mHeap.push_back(t);

  int c1=0 , s1=0; 
  int c2 =0, s2=0, te=0 ;
   ++c2;
   s2+=w;
   te+=w;

int k = 10; //just a random number
   while(k--)
 {
    cin>>t>>w;
    term.push_back(t);
    wght[t] +=w;
    te+= w;
    
    if(t> mHeap[0])
    { mHeap.push_back(t);
     c2++;
     s2+=w;
      
      min_heapifyup(mHeap, c2-1);
      while(2*s1 <te){

        if(2*wght[mHeap[0]]+s1 <=te ){
         MHeap.push_back(mHeap[0]);
         s1+=wght[mHeap[0]]; 
        
         c1++;
         s2-=wght[mHeap[0]];
         c2--;

         auto it= mHeap.begin();
         mHeap.erase(it);
         max_heapifyup(MHeap,c1-1);
         min_heapifyup(mHeap,c2-1);
        }
        else
            break;
      }
    }
    else{
        MHeap.push_back(t);
        ++c1;
        s1+=w;

        max_heapifyup(MHeap, c1-1);
        while(2*s1 > t ){

            s1-= wght[MHeap[0]];
            s2+= wght[MHeap[0]];
            c1--;
            c2++;

            mHeap.push_back(MHeap[0]);
             auto it = MHeap.begin();
             MHeap.erase(it+0);


            max_heapifyup( MHeap, c1-1);
            min_heapifyup(mHeap, c2-1);

             cout<<"minheap is "<<mHeap[c2-1]<<endl;

        } 

    }

    cout<< "median is " <<MHeap[0]<<endl;

 }

return 0;
}