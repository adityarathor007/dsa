int f(int cl,vector<int>&price){
        int ans=price[cl-1];
        if(dp[cl-1]!=-1) return dp[cl-1];

        for(int k=1;k<cl;k++){
            ans=max(ans,f(k,price)+f(cl-k,price));
        }
        return dp[cl-1]=ans;
    }

    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        dp.assign(n,-1);
        return f(n,price);
    }
