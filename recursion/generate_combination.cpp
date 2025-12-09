void recCombine(int num,vector<int>&curr,vector<vector<int>>&ans,int&n,int &k){
        if(curr.size()==k){
            ans.push_back(curr);
            return ;
        }

        for(int j=num+1;j<=n;j++){
            curr.push_back(j);
            recCombine(j,curr,ans,n,k);
            curr.pop_back();
        }

        return;
    }

vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        recCombine(0,curr,ans,n,k);
        return ans;
}
