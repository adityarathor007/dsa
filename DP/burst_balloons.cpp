class Solution {
    vector<vector<int>>dp;
public:
    // int recCalc(int start,int end,vector<int>&nums){
    //     if(start>end) return 0;
    //     if(dp[start][end]!=-1) return dp[start][end];
    //     int max_coins=0;
    //     for(int i=start;i<=end;i++){
    //         int curr_coins=nums[start-1]*nums[i]*nums[end+1];
    //         curr_coins+=recCalc(start,i-1,nums);
    //         curr_coins+=recCalc(i+1,end,nums);
    //         max_coins=max(curr_coins,max_coins);
    //     }

    //     return dp[start][end]=max_coins;

    // }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // dp.assign(n+1,vector<int>(n+1,-1));
        // return recCalc(1,n,nums);

        // tabulation
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int s=n;s>=1;s--){
            for(int e=s;e<=n;e++){
                int max_coins=0;
                for(int k=s;k<=e;k++){
                    int coins=nums[s-1]*nums[k]*nums[e+1];
                    coins+=dp[s][k-1]; //requires smaller e
                    coins+=dp[k+1][e]; //requires larger s
                    max_coins=max(max_coins,coins);
                }
                dp[s][e]=max_coins;
            }
        }

        return dp[1][n];
    }
};
