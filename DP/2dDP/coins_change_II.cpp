class Solution {
    vector<vector<int>>dp;
public:
    int recCount(int i,int amount,vector<int>& coins){
        if(i==coins.size()) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int o1=0;
        if(coins[i]<=amount){
            o1=recCount(i,amount-coins[i],coins);
        }
        int o2=recCount(i+1,amount,coins);
        return dp[i][amount]=o1+o2;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // dp.assign(n,vector<int>(amount+1,-1));
        // return recCount(0,amount,coins);

        dp.assign(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        for(int i=0;i<n;i++){
            for(int camt=1;camt<=amount;camt++){
                long long o1=0;
                if(coins[i]<=camt){
                    o1=dp[i][camt-coins[i]];
                }
                long long o2=i>0?dp[i-1][camt]:0;
                dp[i][camt]=o1+o2;
            }
        }

        return dp[n-1][amount];

    }
};
