#include<iostream>
#include<vector>
using namespace std;

// top_down approach (Memoization)
// int MinArrayJump(vector<int> &v,vector<int> &dp,int i,int n){
//     //base case
//     if(i==n-1){
//         return 0;
//     }

//     //recursive case
//     int max_jump=v[i];
//     if(dp[i]!=0){
//         return dp[i];
//     }
//     int ans=INT_MAX;
//     for(int j=1;j<=max_jump;j++){
//         if(i+j<n){
//             ans=min(ans,MinArrayJump(v,dp,i+j,n));
//         }
        
//     }

//     return dp[i]=ans+1;

// }

int main(){
    vector<int> v{3,4,2,1,2,3,10,1,1,1,2,5};
    int n=v.size();
    // vector<int> dp(n+1,0);
    // cout<<MinArrayJump(v,dp,0,n)<<endl;
    cout<<MinArrayJump(v,n)<<endl;
}