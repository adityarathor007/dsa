int recHelper(int i,int last_max_i,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        if(dp[i][last_max_i+1]!=-1) return dp[i][last_max_i+1];
        int o1=recHelper(i+1,last_max_i,nums,dp);
        int o2=INT_MIN;
        if(last_max_i==-1 or nums[i]>nums[last_max_i]){
            o2=1+recHelper(i+1,i,nums,dp);
        }
        return dp[i][last_max_i+1]=max(o1,o2);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return recHelper(0,-1,nums,dp);
    }
