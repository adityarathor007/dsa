class Solution {
public:
    // memoization
    // int minCoins(vector<int>& coins,int i,int amount,vector<vector<int>>&dp){

    //     if(i==0){
    //         if(amount%coins[i]==0){
    //             return amount/coins[i];
    //         }
    //         return 1e9;
    //     }

    //     if(dp[i][amount]!=-1){
    //         return dp[i][amount];
    //     }



    //     int notTake=0+minCoins(coins,i-1,amount,dp);
    //     int take=INT_MAX;

    //     if(amount>=coins[i]){
    //         take=1+minCoins(coins,i,amount-coins[i],dp);
    //     }

    //     return dp[i][amount]=min(notTake,take);
    // }

    int coinChange(vector<int>& coins, int amount) {
    //    int n = int(coins.size());
    //    vector<vector<int>>dp(n,vector<int>(amount+1,-1));

    //    int ans=minCoins(coins,n-1,amount,dp) ;
    //    return ans!=1e9?ans:-1;


        // tabulation
        int n=int(coins.size());
        // vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        vector<int>prev(amount+1,0),curr(amount+1,0); //more space optimized

        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0){
                prev[t]=t/coins[0];
            }
            else{
                prev[t]=1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                // int notTake=0+dp[i-1][t];
                int notTake=0+prev[t];

                int take=INT_MAX;
                if(coins[i]<=t){
                    // take=1+dp[i][t-coins[i]];
                    take=1+curr[t-coins[i]];
                }

                // dp[i][t]=min(notTake,take);
                curr[t]=min(notTake,take);
            }
            prev=curr;

        }

        // return dp[n-1][amount]!=1e9?dp[n-1][amount]:-1;
        return prev[amount]!=1e9?prev[amount]:-1;

    }
};
