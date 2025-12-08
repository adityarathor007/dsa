int recHelper(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int o1=nums[i]+recHelper(i+2,nums,dp);
        int o2=recHelper(i+1,nums,dp);
        return dp[i]=max(o1,o2);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return recHelper(0,nums,dp);
    }
