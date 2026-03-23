class Solution {
    int MOD=1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<long long>>maxDp(m,vector<long long>(n));
        vector<vector<long long>>minDp(m,vector<long long>(n));

        maxDp[0][0]=minDp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            maxDp[i][0]=minDp[i][0]=grid[i][0]*minDp[i-1][0];
        }

        for(int i=1;i<n;i++){
            maxDp[0][i]=minDp[0][i]=grid[0][i]*minDp[0][i-1];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long a=grid[i][j]*minDp[i-1][j];
                long long b=grid[i][j]*minDp[i][j-1];
                long long c=grid[i][j]*maxDp[i-1][j];
                long long d=grid[i][j]*maxDp[i][j-1];
                minDp[i][j]=min({a,b,c,d});
                maxDp[i][j]=max({a,b,c,d});
            }

        }
        if(maxDp[m-1][n-1]<0) return -1;
        return maxDp[m-1][n-1]%MOD;
    }
};
