#include<iostream>
#include<vector>
using namespace std;


int solve(int n,int k,vector<int>& dp){
    cout<<n<<endl;
    
    if(n==0){
        dp[0]=1;
        return 1;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        if(dp[n-i]!=0 and n-i>=0){
            ans+=dp[n-i];
        }
        else{
            if(n-i>=0){
                dp[n - i] = solve(n - i, k, dp);
                ans += dp[n - i];
            }
            
        }
        
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> dp{n+1,0};
    cout<<solve(n,k,dp)<<endl;
}