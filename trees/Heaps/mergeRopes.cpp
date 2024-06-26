#include<iostream>
#include<queue>
using namespace std;

class Compare{
    public:
        bool operator()(int a,int b){
            return a>b;    //If comp(a, b) returns true, then a is considered to have lower priority than b. this is the interpretation
        }
};

int findMinCost(int arr[],int n){
  
    priority_queue<int,vector<int>,Compare>heap(arr,arr+n); // this method will insert the arr elments in the heap

    int sum=0;
    vector<int> costs;
    while(heap.size()!=1){
        int a1=heap.top();
        heap.pop();
        int a2=heap.top();
        heap.pop();
        int cost =a1+a2;
        sum+=cost;  
       
        heap.push(cost);
    }
    
  
   
    
    return sum;
}

int main(){
    int arr[]={4,3,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findMinCost(arr,n)<<endl;
}