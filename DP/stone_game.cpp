bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0)); //means the biggest number of stones you can get more than the opponent when you pick piles [piles[i],piles[j]]
        for(int i=0;i<n;i++) dp[i][i]=piles[i];
        for(int j=1;j<n;j++){ //the ending index (starting with smaller subarray)
            for(int i=0;i<n-j;i++){ //so that starting index does not exceed the ending index
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>0;
    }
