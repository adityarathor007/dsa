#include<iostream>
#include<vector>
#include<climits>
using namespace std;





long long minimumCost(vector<int> stones, int k){
    //Write your code here. Do not modify the function or the parameters. Use a helper function if needed.
    int n=stones.size();
    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(stones[1]-stones[0]);
    for(int i=2;i<n;i++){
        int j=1;
        while(j<=k and i-j>=0){
            dp[i]=min(dp[i-j]+abs(stones[i]-stones[i-j]),dp[i]);
            j++;
        }
    }
    return dp[n-1];
}



int main(){
    vector<int> a{10,30,40,50,20};
    int k=3;
    cout<<minimumCost(a,k)<<endl;
}