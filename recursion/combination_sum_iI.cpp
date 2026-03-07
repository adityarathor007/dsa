void recFind(int i,vector<int>&curr,vector<vector<int>>&ans,vector<int>&candidates,int target){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    int n=candidates.size();
    for(int j=i;j<n;j++){
        if(j>i and candidates[j]==candidates[j-1]) continue; //to avoid duplicates

        if(candidates[j]<=target){
            curr.push_back(candidates[j]);
            recFind(j+1,curr,ans,candidates,target-candidates[j]);
            curr.pop_back();
        }
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>curr;
    sort(candidates.begin(),candidates.end());  //so that the suitable vectors
    recFind(0,curr,ans,candidates,target);
    return ans;
}
