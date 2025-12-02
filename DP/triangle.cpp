int recHelper(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()) return 0;
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int min_child_sum=min(recHelper(i+1,j,triangle,dp),recHelper(i+1,j+1,triangle,dp));
        return dp[i][j]=triangle[i][j]+min_child_sum;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,INT_MAX));
        return recHelper(0,0,triangle,dp);

    }
