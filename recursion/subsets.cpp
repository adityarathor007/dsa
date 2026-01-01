class Solution {
public:
    void recAdd(int i,vector<int>&curr,vector<int>&nums,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }

        recAdd(i+1,curr,nums,ans);
        curr.push_back(nums[i]);
        recAdd(i+1,curr,nums,ans);
        curr.pop_back();

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        recAdd(0,curr,nums,ans);

        return ans;
    }
};
