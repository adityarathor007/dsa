#include<bits/stdc++.h>
using namespace std;


long long coinChange(int n,vector<int>&coins,long long s,vector<vector<int>>&dp){
    //base case
    if(dp[n][s]!=0){
        return dp[n][s];
    }

    if((s==0 and n==0) or n==0){
        return dp[n][s]=1;
    }
    if(s==0){
        return dp[n][s]=0;
    }
    
    long long inc=0,exc=0;
    if(n-coins[s-1]>=0){
        inc=coinChange(n-coins[s-1],coins,s,dp);  //case when the coins[s-1] is deducted from the total n
    }
    exc=coinChange(n,coins,s-1,dp);
    long long ans=inc+exc;
    return dp[n][s]=ans;
    
}





long long findCombinations(int n, vector<int> coins){
    //Write your code here. Do not modify the function or parameters. You can use helper function if needed.
    long long s=coins.size();
    return coinChange(n,coins,s);
}


int main(){
    int n=4;
    vector<int>coins{1,2,3};
    cout<<findCombinations(n,coins)<<endl;
    return 0;
}