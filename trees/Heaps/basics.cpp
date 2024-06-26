
 
#include <iostream>
#include <queue>
using namespace std;

class Compare{
    public:
        bool operator()(int a,int b){
            return a>b;    //If comp(a, b) returns true, then a is considered to have lower priority than b. this is the interpretation
        }
};


int main(){
    int arr[]={10,15,20,13,6,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,Compare>heap;
    
    for(int x:arr){
        heap.push(x);
    }
    
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    
    
}

