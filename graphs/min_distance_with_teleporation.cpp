class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int maxValue=0;
        int m=grid.size(),n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxValue=max(maxValue,grid[i][j]);
            }
        }

        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>temp(maxValue+1,INT_MAX);

        temp[grid[m-1][n-1]]=0;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1) continue;
                int right=j<n-1?dp[i][j+1]+grid[i][j+1]:INT_MAX;
                int bottom=i<m-1?dp[i+1][j]+grid[i+1][j]:INT_MAX;
                dp[i][j]=min(right,bottom);
                // Update the best known cost for this cell's value
                temp[grid[i][j]]=min(temp[grid[i][j]],dp[i][j]);
            }
        }

        vector<int>best(maxValue+1,0);
        for(int x=0;x<k;x++){
            // 1. Build Prefix Minimum Array
            // best[v] = min cost obtainable from any cell with value <= v
            best[0]=temp[0];
            for(int val=1;val<=maxValue;val++){
                best[val]=min(best[val-1],temp[val]);
            }

            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==m-1 and j==n-1) continue;

                    int down=i<m-1?dp[i+1][j]+grid[i+1][j]:INT_MAX;
                    int right=j<n-1?dp[i][j+1]+grid[i][j+1]:INT_MAX;
                    int walkCost=min(down,right);
                    int teleportCost=best[grid[i][j]];

                    dp[i][j]=min(walkCost,teleportCost);

                    temp[grid[i][j]]=min(temp[grid[i][j]],dp[i][j]);

                }
            }

        }

        return dp[0][0];
    }
};
