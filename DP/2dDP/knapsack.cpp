#include<iostream>
#include<vector>
using namespace std;    


// top down dp
int findMaxProfit(int n,int wt,vector<int>&wts,vector<int>&prices,vector<vector<int>>&dp){
    //base case
    if(n==0 or wt==0){
        return 0;
    }
    if(dp[n][wt]!=0){
        return dp[n][wt];
    }
    int inc=0;
    if(wt-wts[n-1]>=0){
        inc=prices[n-1]+findMaxProfit(n-1,wt-wts[n-1],wts,prices,dp);
    }
    
    int exc=findMaxProfit(n-1,wt,wts,prices,dp);
    return dp[n][wt]=max(inc,exc);
}


// bottom-up dp
int findMaxProfit(int n,int wt,vector<int>&wts,vector<int>prices){
    vector<vector<int>>dp(n+1,vector<int>(wt+1,0)); //stores the profit for i items and j capicity of the bag
    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            int inc=0,exc=0;
            if(wts[i-1]<=j){
                inc+=prices[i]+dp[i-1][j-wts[i-1]];
            }
            exc+=dp[i-1][j];
            dp[i][j]=max(inc,exc);
        }
    }

    return dp[n][wt];
}






int main(){
    int n=4;
    int wt=11;
    vector<int>wts{2,7,3,4};
    vector<int>prices{5,20,20,10};


    // vector<vector<int>>dp(n+1,vector<int>(wt+1,0));
    // cout<<findMaxProfit(n,wt,wts,prices,dp)<<endl;  //f(n,w) denotes the maxProfit for n items and and bag with weight wt

    cout<<findMaxProfit(n,wt,wts,prices)<<endl;


}