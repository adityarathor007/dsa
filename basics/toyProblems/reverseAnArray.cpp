#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr,int i,int n){
    if(i>=n/2){
        return ;
    }
    int temp=arr[i];
    arr[i]=arr[n-i-1];
    arr[n-i-1]=temp;
    reverseArray(arr,i+1,n);

    return ;
}


int main(){
    vector<int> arr{1,2,4,5};
    int n=arr.size();
    reverseArray(arr,0,n);
    for(auto x:arr){
        cout<<x<<",";
    }
    cout<<endl;
}