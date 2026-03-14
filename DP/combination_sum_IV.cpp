
    int recSolve(int target,vector<int>& nums){
        if(target==0) return 1;

        if(dp[target]!=-1) return dp[target];

        int cnt=0;
        for(int num:nums){
            if(num>target) continue;
            cnt+=recSolve(target-num,nums);
        }
        return dp[target]=cnt;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target+1,-1);
        return recSolve(target,nums);
    }
