int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1); //storing the min cost to climb from ith index to top
        for(int i=n-1;i>=0;i--){
            dp[i]+=cost[i];
            if(i<n-1) dp[i]+=min(dp[i+1],dp[i+2]);
            
        }
        return min(dp[0],dp[1]);
    }