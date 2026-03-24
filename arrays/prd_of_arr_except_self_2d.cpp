vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

       vector<vector<int>>ans(n,vector<int>(m,-1));
       int len=m*n;
       long long prefix=1;

       //going in order as if the array is flattened
       for(int i=0;i<len;i++){
        int x=i/m;
        int y=i%m;
        ans[x][y]=prefix;
        prefix=(prefix*grid[x][y])%MOD;
       }

       long long suffix=1;
       for(int i=len-1;i>=0;i--){
        int x=i/m;
        int y=i%m;
        ans[x][y]=(ans[x][y]*suffix)%MOD;
        suffix=(suffix*grid[x][y])%MOD;
       }

        return ans;
    }
