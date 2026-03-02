vector<vector<int>>dp;
int recCount(int i,int j,string &s,string &t){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        int o1=recCount(i+1,j+1,s,t);
        int o2=recCount(i+1,j,s,t);
        return dp[i][j]=o1+o2;
    }

    return dp[i][j]=recCount(i+1,j,s,t);

}
int numDistinct(string s, string t) {
    int m=s.size();
    int n=t.size();
    // dp.assign(m,vector<int>(n,-1));
    // return recCount(0,0,s,t);

    vector<vector<unsigned long>>dp(m+1,vector<unsigned long>(n+1,0));
    for(int i=0;i<m;i++) dp[i][0]=1; //An empty t is a subsequence of any prefix of s (i.e any len 'i') in exactly 1 way

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[m][n];
}
