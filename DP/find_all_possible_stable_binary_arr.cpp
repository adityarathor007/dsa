// zc: contains remaining zeros
// oc: ones remaning
// prev: what was the prev element
// cl: how many more of prev you can place

vector<vector<vector<vector<int>>>>dp;
int recCount(int zc,int oc,int prev,int cl,int limit){

    if(cl < 0) return 0;
    if(zc==0 && oc==0) return 1;

    if(dp[zc][oc][prev][cl]!=-1) return dp[zc][oc][prev][cl];
    long long cnt=0;

    if(zc>0){
        if(prev==0)
            cnt += recCount(zc-1,oc,prev,cl-1,limit,dp);
        else
            cnt += recCount(zc-1,oc,0,limit-1,limit,dp);
    }

    if(oc>0){
        if(prev==1)
            cnt += recCount(zc,oc-1,prev,cl-1,limit,dp);
        else
            cnt += recCount(zc,oc-1,1,limit-1,limit,dp);
    }

    return dp[zc][oc][prev][cl] = cnt % MOD;
}


int numberOfStableArrays(int zero, int one, int limit) {
        dp.assign(zero+1,vector<vector<vector<int>>>(one+1,vector<vector<int>>(2,vector<int>(limit,-1))));
        return (recCount(zero-1,one,0,limit-1,limit)+recCount(zero,one-1,1,limit-1,limit))%MOD;
}
