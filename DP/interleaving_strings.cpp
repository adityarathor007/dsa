int recHelper(int i,int j,string&s1,string&s2,string&s3,vector<vector<int>>&dp){
        if(i+j==s3.size()) return true;
        int m=s1.size();
        int n=s2.size();

        if(i==m){
            return s2.substr(j,n-j+1)==s3.substr(i+j,n+m-(i+j)+1);
        }

        if(j==n){
            return s1.substr(i,m-i+1)==s3.substr(i+j,n+m-(i+j)+1);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s3[i+j]){
            if(recHelper(i+1,j,s1,s2,s3,dp)) return dp[i][j]=1;
        }
        if(j<s2.size() and s2[j]==s3[i+j]){
            if(recHelper(i,j+1,s1,s2,s3,dp)) return dp[i][j]=1;
        }
        if(i<s1.size() and j<s2.size()) return dp[i][j]=0;
        return 0;
    }


    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(s3.size()!=n+m) return false;
        if(m==0) return s2==s3;
        if(n==0) return s1==s3;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recHelper(0,0,s1,s2,s3,dp);

    }
