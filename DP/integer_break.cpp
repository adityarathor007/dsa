int recSolve(int n){
        if(n<2) return 1;

        if(dp[n]!=-1) return dp[n];

        int cmax=INT_MIN;
        for(int i=1;i<=n;i++){
            cmax=max(cmax,i*recSolve(n-i));
        }

        return dp[n]=cmax;
    }

    int integerBreak(int n) {
        dp.assign(n+1,-1);
        if(n==2) return 1; //few edge cases
        if(n==3) return 2;
        dp[2]=2;
        dp[3]=3;
        return recSolve(n);
    }
