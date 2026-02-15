class Solution {
    unordered_set<int>visited;
public:
    void recGenerate(vector<int>curr,vector<int>&nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(curr.size()==n){
            ans.push_back(curr);
        }

        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                if(i!=0 and nums[i]==nums[i-1] and !visited.count(i-1)) continue;
                curr.push_back(nums[i]);
                visited.insert(i);
                recGenerate(curr,nums,ans);
                curr.pop_back();
                visited.erase(i);
            }
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        recGenerate(curr,nums,ans);


        return ans;
    }
};
