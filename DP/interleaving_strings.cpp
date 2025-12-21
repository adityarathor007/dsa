 bool recHelper(int i,int j,string& s1,string& s2,string& s3,vector<vector<int>>&dp){
        if(i+j==s3.size()) return true;

        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.size() and s1[i]==s3[i+j] and recHelper(i+1,j,s1,s2,s3,dp)) return dp[i][j]=1;
        if(j<s2.size() and s2[j]==s3[i+j] and recHelper(i,j+1,s1,s2,s3,dp)) return dp[i][j]=1;

        return dp[i][j]=0;

    }


 bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recHelper(0,0,s1,s2,s3,dp);
    }
