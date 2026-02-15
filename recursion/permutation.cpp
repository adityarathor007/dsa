void recGenerate(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return ;
        }
        int n=nums.size();

        for(int j=0;j<n;j++){
            if(nums[j]!=INT_MIN){
                int curr_num=nums[j];
                nums[j]=INT_MIN;
                curr.push_back(curr_num);
                recGenerate(i+1,nums,curr,ans);
                curr.pop_back();
                nums[j]=curr_num;
            }
        }
        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();
        recGenerate(0,nums,curr,ans);
        return ans;
    }
