#include<iostream>
#include<vector>
using namespace std;


//top down(memoisation)
int countTree(int n,vector<int> &dp){
    if(n==1 or n==0){
        return 1;
    }

    if(dp[n]!=0){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
         ans+=countTree(i-1,dp)*countTree(n-i,dp);
    }
    return dp[n]=ans;
}


//bottom up(how it is related with previous element)
int countTree(int n){
    vector<int> dp(n+1,0); //if ith element is the root then the number of possible ways to make bst
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        for(int k=1;k<=i;k++)
            dp[i]+=(dp[k-1]*dp[i-k]);
    
    return dp[n];
}

int main(){
     int n=3;
    //  vector<int> dp(n+1,0);
     cout<<countTree(n)<<endl;
}