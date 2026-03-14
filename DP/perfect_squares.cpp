int recCount(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int cnt=1e9;
        for(int i=1;i<=sqrt(n);i++){
            int square = i * i;
            cnt = min(cnt, 1 + recCount(n - square));
        }
        return dp[n]=cnt;
    }

    int numSquares(int n) {
        dp.assign(n+1,-1);
        return recCount(n);
    }
