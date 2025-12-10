void recHelper(int index,int csum,vector<int>&curr,int &target,vector<int>&candidates,vector<vector<int>>&ans){
        if(target==csum){
            ans.push_back(curr);
            return;
        }
        int n=candidates.size();
        if(index==candidates.size() or csum>target){
            return;
        }
        recHelper(index+1,csum,curr,target,candidates,ans);
        if(candidates[index]+csum<=target){
            curr.push_back(candidates[index]);
            recHelper(index,csum+candidates[index],curr,target,candidates,ans);
            curr.pop_back();
        }

        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        recHelper(0,0,curr,target,candidates,ans);
        return ans;
    }
