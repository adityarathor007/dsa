int recHelper(int i,int curr_amt,vector<int>&coins,int amount,vector<vector<int>>&dp){
    if(curr_amt==amount) return 0;
        if(i<0) return 1e9;

        if(dp[i][curr_amt]!=-1) return dp[i][curr_amt];

        int o1=recHelper(i-1,curr_amt,coins,amount,dp);
        int o2=1e9;
        if(coins[i]+curr_amt<=amount){
            o2=1+recHelper(i,curr_amt+coins[i],coins,amount,dp);
        }
        return dp[i][curr_amt]=min(o1,o2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        // memoization
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int curr_amt=0;
        // int ans=recHelper(n-1,curr_amt,coins,amount,dp);
        // if(ans==1e9) return -1;
        // return ans;

        // tabulation
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0),curr(amount+1,0);

        for(int curr_amt=1;curr_amt<=amount;curr_amt++){
            if(coins[0]<=curr_amt){
                // dp[0][curr_amt]=dp[0][curr_amt-coins[0]];
                // if(dp[0][curr_amt-coins[0]]!=1e9) dp[0][curr_amt]+=1;
                curr[curr_amt]=curr[curr_amt-coins[0]];
                if(curr[curr_amt]!=1e9) curr[curr_amt]+=1;
            }
            // else dp[0][curr_amt]=1e9;
            else curr[curr_amt]=1e9;
        }

        prev=curr;

        for(int i=1;i<n;i++){
            for(int curr_amt=1;curr_amt<=amount;curr_amt++){
                // int o1=dp[i-1][curr_amt];
                int o1=prev[curr_amt];
                int o2=1e9;
                if(coins[i]<=curr_amt){
                    // o2=1+dp[i][curr_amt-coins[i]];
                    o2=1+curr[curr_amt-coins[i]];
                }
                // dp[i][curr_amt]=min(o1,o2);
                curr[curr_amt]=min(o1,o2);
            }
            prev=curr;
        }

        // if(dp[n-1][amount]==1e9) return -1;
        // return dp[n-1][amount];
        if(curr[amount]==1e9) return -1;
        return curr[amount];
    }
