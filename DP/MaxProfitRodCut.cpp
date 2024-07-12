#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// int MaxProfit(int n,vector<int>& price,vector<int>&dp){
//     if(n==0){
//         return 0;
//     }

//     if(dp[n]!=0){
//         return dp[n];
//     }

//     int s=price.size();
//     int ans=INT_MIN;
//     for(int i=0;i<s;i++){
//         if(n-i-1>=0){
//             ans=max(ans,price[i]+MaxProfit(n-i-1,price,dp));
//         }

//     }
//     return dp[n]=ans;
// }

// Bottom Up Approach
int MaxProfit(int n,vector<int>& price){
    vector<int>dp(n+1); //storing the max_price for cut                 
    dp[0]=0;
    for(int len=1;len<=n;len++){
        int ans=INT_MIN;

        for(int i=0;i<len;i++){
            int cut=i+1;
            int current_price=price[i]+dp[len-cut];
            ans=max(ans,current_price);
        }
        dp[len]=ans;
    }
    return dp[n];

}



int main(){
    vector<int> price{1,5,8,9,10,17,17,20}; //if price[i] then cut is of i+1 because of diff in 0 and 1 indexing
    int n=8;
    // vector<int>dp(n+1,0);
    cout<<MaxProfit(n,price)<<endl;
}