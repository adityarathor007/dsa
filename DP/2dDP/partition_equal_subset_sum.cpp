
vector<vector<int>>dp;

bool findSubseq(int i,int target,vector<int>&nums){
    if(target==0) return true;
    if(i==nums.size() or target<0) return false;

    if(dp[i][target]!=-1) return dp[i][target];

    return dp[i][target]=findSubseq(i+1,target-nums[i],nums) or findSubseq(i+1,target,nums);
}

bool canPartition(vector<int>& nums) {
    int totalSum=0;
    for(int num:nums) totalSum+=num;
    if(totalSum&1) return false;
    int n=nums.size();

    dp.assign(n,vector<int>(totalSum/2+1,-1));
    return findSubseq(0,totalSum/2,nums);
}
