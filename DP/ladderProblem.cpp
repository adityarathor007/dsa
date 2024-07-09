#include<iostream>
#include<vector>
using namespace std;

//using the top_down dp O(n*k)
// int solve(int n,int k,vector<int>& dp){
//     cout<<n<<endl;
    
//     if(n==0){
//         dp[0]=1;
//         return 1;
//     }
//     int ans=0;
//     for(int i=1;i<=k;i++){
//         if(dp[n-i]!=0 and n-i>=0){
//             ans+=dp[n-i];
//         }
//         else{
//             if(n-i>=0){
//                 dp[n - i] = solve(n - i, k, dp);
//                 ans += dp[n - i];
//             }
            
//         }
        
//     }
//     return ans;
// }


// using the bottom down approach(O(n*k))
// int solve(int n,int k){
    // vector<int> dp(n+1,0);

    // dp[0]=0;
    // if(n==0){
    //     return dp[0];
    // }
    // for(int i=1;i<=n;i++){

    //     for(int jump=1;jump<=k;jump++)
    //         if(i-jump>=0){
    //             dp[i] += dp[i - jump];
    //         }
            
    // }
    // return dp[n];
// 

// }


// using the optimised method in bottom approach(O(n+h))  Linear time from exponentioal time in recursion


int solve(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    if(n==0||n==1){
        return dp[n];
    }
    for(int i=2;i<=k;i++){
        dp[i]+=2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        dp[i]+=2*dp[i-1]-dp[i-k-1];
    }

    return dp[n];
}






int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    // vector<int> dp{n+1,0};
    cout<<solve(n,k)<<endl;
}