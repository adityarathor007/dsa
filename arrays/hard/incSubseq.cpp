#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findLongestSubSeq(vector<int>&arr,int i,int prev_in,vector<vector<int>>&dp){
    if(i==arr.size()){
        return 0;
    }
    
    if(dp[i][prev_in+1]!=-1){
        return  dp[i][prev_in+1];
    }
    
    
    if(prev_in==-1 || arr[prev_in]<arr[i]){
        return dp[i][prev_in+1]=max(findLongestSubSeq(arr, i+1, prev_in,dp),1+findLongestSubSeq(arr, i+1, i,dp));
    }
    
    return dp[i][prev_in+1]=findLongestSubSeq(arr, i+1, prev_in,dp);
   
}

int main(){
    vector<int>arr{2,10,1,3};
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));


    cout<<findLongestSubSeq(arr,0,-1,dp)<<endl;
    
    return 0;

}
