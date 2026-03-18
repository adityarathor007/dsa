int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]>k) return 0;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int csum=grid[i][j];
                if(i) csum+=grid[i-1][j];
                grid[i][j]=csum;
                if(csum<=k) cnt+=1;
            }
        }

        return cnt;
    }
