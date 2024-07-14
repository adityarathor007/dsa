#include<iostream>
using namespace std;

// problem: a frog can jump from i to i+1 and i+2 and the cost incurred will be abs(h[i]-h[j]) for any jump and we have to find the min_cost for jump to last stone


//bottom up appr
int minCost(int n,vector<int> arr){
    vector<int> minCostArr(n,0);

    minCostArr[0]=0;
    minCostArr[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        int x1=minCostArr[i-1]+abs(arr[i]-arr[i-1]);
        int x2=minCostArr[i-2]+abs(arr[i]-arr[i-2]);
        minCostArr[i]=min(x1,x2);
    }
    return minCostArr[n-1];
    

};




int main(){
    int n=6;
    // vector<int> arr{10,30,40,20};
    vector<int> arr{30,10,60,10,60,50};
    
    cout<<minCost(n,arr)<<endl;
}