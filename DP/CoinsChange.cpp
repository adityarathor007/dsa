#include<iostream>
#include <vector>
#include <limits.h>
using namespace std;

// using the top down approach
// int findMinChange(int n,vector<int>& coins,vector<int> &dp){
//     cout<<"the value of n is: "<<n<<endl;
//     if(n==0){
//         return 0;
//     }
    
//     int ans=INT_MAX;
//     for(auto x:coins){
//         if(n-x>=0){
//             if(dp[n-x]==0){
//                 dp[n-x]=findMinChange(n-x,coins,dp);
//             }
//             ans=min(dp[n-x],ans);
//         }
//     }

//     return dp[n] = ans + 1;

// }

// using the bottom up approach(iterative approach)
int findMinChange(int n,vector<int> & coins){
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
         dp[i]=INT_MAX;
        for(auto x:coins){
            if(i-x>=0 and dp[i-x]!=INT_MAX){ //the second and is important as dp[i-x]=14-5=>9 will be INTMAX and adding 1 will make it INT_MIN which will further cause error for n=14 & coins equal to {5,7,10 }
                dp[i]=min(dp[i],dp[i-x]+1);
            }
        }
       
    }
    return dp[n]=INT_MAX?-1:dp[m];  //returning -1 if no case is possible
}



int main(){
    int n=14;
    vector<int> coins{5,7,10};
    // vector<int> dp(n+1,0);
    cout<<findMinChange(n,coins)<<endl;
    // cout<<"the dp vector is"<<endl;
    // for(auto x:dp){
    //     cout<<x<<",";
    // }
    // cout<<endl;


}
