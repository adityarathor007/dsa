#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

bool canDivide(vector<int> arr, int k , int val){
    int sum=accumulate(arr.begin(),arr.end(),0);
    int c_sum=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(c_sum+arr[i]>=val){
            count+=1;
            c_sum=0;
        }
        else{
            c_sum+=arr[i];
        }
    }
    return count>=k;
}



int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    int s=arr[0];
    int e=accumulate(arr.begin(),arr.end(),0);
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(canDivide(arr,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    
    
  return ans;  
    
}

int main(){
    vector<int> i={1,2,3,4};
    sort(i.begin(),i.end());
    int k=3;
    cout<<getCoins(i,k)<<endl;
    
}