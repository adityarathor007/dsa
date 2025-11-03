// int f(int index,int cj,vector<int>&nums,vector<vector<int>>&dp){
    //     if(index>=nums.size()-1){
    //         return cj;
    //     }

    //     if(dp[index][cj]!=-1) return dp[index][cj];

    //     int ans=INT_MAX;

    //     for(int jump=nums[index];jump>=1;jump--){
    //         ans=min(ans,f(index+jump,cj+1,nums,dp));
    //     }

    //     return dp[index][cj]=ans;
    // }

    int jump(vector<int>& nums) {

        //solving using dp (TLE)
        // int n=nums.size();
        // int current_jumps=0;
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,current_jumps,nums,dp);


        //carrying over the range
        int n=nums.size();
        int jumps=0;
        int l=0,r=0;
        while(r<n-1){
            int farthest_index=0;
            for(int i=l;i<=r;i++){
                farthest_index=max(farthest_index,i+nums[i]);
            }
            l=r+1;
            r=farthest_index;
            jumps+=1;
        }


        return jumps;

    }
