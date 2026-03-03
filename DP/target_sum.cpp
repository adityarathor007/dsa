vector<vector<int>>dp;

// int recCnt(int i,int ctarget,vector<int>&nums){
//     if(i==nums.size()) return ctarget==0;

//     int o1=recCnt(i+1,ctarget-nums[i],nums);
//     int o2=recCnt(i+1,ctarget+nums[i],nums);
//     return o1+o2;
// }

int recCnt(int i,int ctarget,vector<int>&nums,int& offset){

    if(i==nums.size()) return ctarget==0;
    if(abs(ctarget)>offset) return 0;
    if(dp[i][ctarget+offset]!=-1) return dp[i][ctarget+offset];

    return dp[i][ctarget+offset]=recCnt(i+1,ctarget+nums[i],nums,offset)+recCnt(i+1,ctarget-nums[i],nums,offset);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    for(int num:nums){
        sum+=num;
    }
    if(abs(target)>sum) return 0;
    int n=nums.size();
    dp.assign(n,vector<int>(2*sum+1,-1));
    return recCnt(0,target,nums,sum);
}
