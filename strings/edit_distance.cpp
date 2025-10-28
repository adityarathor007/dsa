 int countEdits(int i1,int i2,string &word1,string &word2,vector<vector<int>>&dp){

        if(i2==word2.size()){
            return word1.size()-i1; //deleting the remaning characters from word1
        }
        if(i1==word1.size()){
            return word2.size()-i2; //inserting new chars at last to match the word2
        }

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(word1[i1]==word2[i2]){
            return dp[i1][i2]=countEdits(i1+1,i2+1,word1,word2,dp);
        }

        int edits=min(countEdits(i1+1,i2,word1,word2,dp),min(countEdits(i1+1,i2+1,word1,word2,dp),countEdits(i1,i2+1,word1,word2,dp)));
        return dp[i1][i2]=1+edits;

    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countEdits(0,0,word1,word2,dp);
    }
