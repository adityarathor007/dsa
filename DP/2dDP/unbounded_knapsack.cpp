 int maxProfit(int i,int cap,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
        if(i<0){
            return 0;
        }

        if(dp[i][cap]!=-1){
            return dp[i][cap];
        }


        int notTake=maxProfit(i-1,cap,val,wt,dp);
        int take=0;
        if(cap>=wt[i]){
            take=val[i]+maxProfit(i,cap-wt[i],val,wt,dp);
        }

        return dp[i][cap]=max(notTake,take);

    }


    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=int(val.size());
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return maxProfit(n-1,capacity,val,wt,dp);

    }
