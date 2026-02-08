#include<iostream>
#include<vector>
using namespace std;


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
