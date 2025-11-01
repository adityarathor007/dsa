  bool recHelper(int index,vector<int>& nums,vector<int>&dp){
        if(index==nums.size()-1) return true;

        if(dp[index]!=-1) return dp[index];

        for(int jump=1;jump<=nums[index];jump++){
            if(recHelper(index+jump,nums,dp)) return dp[index]=true;
        }
        return dp[index]=false;

    }
    bool canJump(vector<int>& nums) {

        // recursive solution

        // int n=nums.size();
        // vector<int>dp(n,-1);
        // return recHelper(0,nums,dp);


        //iterative solution using max_index
        int max_i=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>max_i) return false;
            max_i=max(max_i,i+nums[i]);
        }
        return true;
    }
