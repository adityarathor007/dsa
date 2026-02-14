class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {

        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }


        int ans=INT_MAX;

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int prev_move=INT_MAX;
                for(int k=0;k<n;k++){
                    int val=grid[i-1][k];
                    prev_move=min(prev_move,dp[i-1][k]+moveCost[val][j]);
                }
                dp[i][j]=prev_move+grid[i][j];
                if(i==m-1) ans=min(ans,dp[i][j]);
            }
        }
        return ans;

    }
};
