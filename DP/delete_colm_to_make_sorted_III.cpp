int recHelper(int j,int prev,vector<string>& strs){
        int n = strs.size();
        int m = strs[0].size();
        if(j==m) return 0;
        if(dp[j][prev+1]!=-1) return dp[j][prev+1];

        int res = 1 + recHelper(j + 1, prev, strs);

        bool canKeep=true;
        if(prev!=-1){
            for(int i=0;i<n;i++){
                if(strs[i][j]<strs[i][prev]){
                    canKeep=false;
                    break;
                }
            }
        }

        if(canKeep) res=min(res,recHelper(j+1,j,strs));
        return dp[j][prev+1] = res;

    }

    int minDeletionSize(vector<string>& strs) {
        int ans=recHelper(0,-1,strs);
        return ans;
    }
   