void recHelper(int cnum,int csum,vector<int>&curr,vector<vector<int>>&ans,int k,int n){
        if(curr.size()==k){
            if(csum==n) ans.push_back(curr);
            return;
        }

        for(int i=cnum+1;i<10;i++){
            curr.push_back(i);
            recHelper(i,csum+i,curr,ans,k,n);
            curr.pop_back();
        }

        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        int csum=0;
        recHelper(0,csum,curr,ans,k,n);

        return ans;
    }