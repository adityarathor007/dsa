void recSolve(int i,vector<int>&curr,vector<vector<int>>&ans,vector<int>& nums){
    ans.push_back(curr);
    int n=nums.size();
    for(int j=i;j<n;j++){
        if(j>i and nums[j]==nums[j-1]) continue;
        curr.push_back(nums[j]);
        recSolve(j+1,curr,ans,nums);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>curr;
    sort(nums.begin(),nums.end());
    recSolve(0,curr,ans,nums);

    return ans;
}
