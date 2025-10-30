#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int findMaxSubarraySum(vector<int>arr){
    
    // 2pointer approach
    // int i=0;
    // int j=0;
    // int ans=INT_MIN;
    // int c_sum=0;
    // pair<int,int>p;
    // while(j<arr.size()){
    //     c_sum+=arr[j];
    //      if(c_sum<ans){
    //         while(c_sum<ans and i!=j){
    //             c_sum-=arr[i];
    //             i++;
    //         }
    //     }
    //     if(c_sum>ans){ 
    //         ans=c_sum;
    //     }
    //    j++;

    // }
    // return ans;


    // using kadane's algo(intution: it carries the maxSum as it traverses)
    int ans=arr[0];
    int c_sum=0;
    int n=arr.size();
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        if(c_sum==0){
            start=i; 
        }
        c_sum+=arr[i];
        if(c_sum>ans){
            ans=c_sum;
            end=i;
        }
        if(c_sum<0){
            c_sum=0;
           
        }
    }
    cout<<start<<" - "<<end<<endl;
    return ans;
}

int main(){
    vector<int>arr{-2,-3,4,-1,-2,1,5,-3};
    cout<<findMaxSubarraySum(arr)<<endl;
}