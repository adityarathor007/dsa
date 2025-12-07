void recPermute(vector<int>&nums,vector<int>&curr,vector<bool>&used,vector<vector<int>>&ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            curr.push_back(nums[i]);
            recPermute(nums,curr,used,ans);
            used[i]=0;
            curr.pop_back();

        }
        return;


    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<bool>used(n);
        vector<int>curr;
        recPermute(nums,curr,used,ans);
        return ans;
    }
