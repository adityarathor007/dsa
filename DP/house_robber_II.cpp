class Solution {
    vector<vector<int>>dp;
public:
    int recMax(int i,bool isStart,vector<int>&nums){
        int n=nums.size();
        if(i>=n) return 0;

        if(dp[i][isStart]!=-1) return dp[i][isStart];
        if(i==n-1){
            if(isStart) return dp[i][isStart]=0;
            else return dp[i][isStart]=nums[i];
        }

        int o1=nums[i]+recMax(i+2,isStart,nums);
        int o2=recMax(i+1,isStart,nums);
        return dp[i][isStart]=max(o1,o2);

    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(2,-1));
        int ans=nums[0]+recMax(2,true,nums);
        ans=max(ans,recMax(1,false,nums));
        return ans;w
    }
};
