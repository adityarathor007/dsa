#include<iostream>
#include <vector>
#include <limits.h>
using namespace std;

// using the top down approach
int findMinChange(int n,vector<int>& coins,vector<int> &dp){
    cout<<"the value of n is: "<<n<<endl;
    if(n==0){
        return 0;
    }
    
    int ans=INT_MAX;
    for(auto x:coins){
        if(n-x>=0){
            if(dp[n-x]==0){
                dp[n-x]=findMinChange(n-x,coins,dp);
            }
            ans=min(dp[n-x],ans);
        }
    }

    return dp[n] = ans + 1;

}



int main(){
    int n=6;
    vector<int> coins{1,6};
    vector<int> dp(n+1,0);
    cout<<findMinChange(n,coins,dp)<<endl;
    cout<<"the dp vector is"<<endl;
    for(auto x:dp){
        cout<<x<<",";
    }
    cout<<endl;


}
