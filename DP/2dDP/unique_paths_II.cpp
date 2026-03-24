vector<vector<int>>dirn{{0,-1},{-1,0}};

int recHelper(int x,int y,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(x==0 and y==0) return 1;

        if(dp[x][y]!=-1) return dp[x][y];

        int paths=0;
        for(int i=0;i<2;i++){
            int nx=x+dirn[i][0];
            int ny=y+dirn[i][1];
            if(nx<m and ny<n and obstacleGrid[nx][ny]!=1){
                paths+= recHelper(nx,ny,obstacleGrid,dp);
            }
        }
        return dp[x][y]=paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;

        // using memoization
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] or obstacleGrid[m-1][n-1]) return 0;
        // vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>curr(n,0),prev(n,0);
        curr[0]=1;

        // dp[0][0]=1;
        // for(int i=1;i<m;i++){
        //     if(obstacleGrid[i][0]) break;
        //     dp[i][0]=1;
        // }

        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]) break;
            // dp[0][i]=1;
            curr[i]=1;
        }
        prev=curr;

        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]) curr[0]=0;
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]){
                    curr[j]=0;
                    continue;
                }
                // dp[i][j]=dp[i-1][j]+dp[i][j-1];
                curr[j]=curr[j-1]+prev[j];
            }
            prev=curr;
        }

        // return dp[m-1][n-1];
        return curr[n-1];
    }
