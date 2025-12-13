int countEdits(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i==s1.size() and j==s2.size()) return 0;
        if(i==s1.size())     return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=countEdits(i+1,j+1,s1,s2,dp);

        int o1=countEdits(i,j+1,s1,s2,dp); //inserting the character
        int o2=countEdits(i+1,j,s1,s2,dp);  //deleting the character
        int o3=countEdits(i+1,j+1,s1,s2,dp); //replacing a character
        return dp[i][j]=1+min(o1,min(o2,o3));

    }

    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countEdits(0,0,word1,word2,dp);
    }
