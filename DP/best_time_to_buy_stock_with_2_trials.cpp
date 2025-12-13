int recHelper(int i,int cnt,vector<int>&prices,vector<vector<int>>&dp){
        if(cnt==4 or i==prices.size()){
            return 0;
        }

        if(dp[i][cnt]!=-1) return dp[i][cnt];

        if((cnt&1)==0){
            int o1=-prices[i]+recHelper(i+1,cnt+1,prices,dp);
            int o2=recHelper(i+1,cnt,prices,dp);
            return  dp[i][cnt]=max(o1,o2);
        }
        int o1=recHelper(i+1,cnt,prices,dp);
        int o2=prices[i]+recHelper(i+1,cnt+1,prices,dp);
        return dp[i][cnt]=max(o1,o2);

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return recHelper(0,0,prices,dp);
    }
