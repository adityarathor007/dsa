
    bool checkWord(string cw,unordered_set<string>&wordSet){
        cout<<cw<<endl;
        return wordSet.count(cw)?true:false;
    }

    bool recHelper(int i,string s,unordered_set<string>&wordSet,vector<int>&dp){
        if(i==s.size()) return true; //before all partition were present in the wordSet

        int n=s.size();
        if(dp[i]!=-1) return dp[i];

        for(int k=i;k<n;k++){
            if(checkWord(s.substr(i,k-i+1),wordSet)){
                //possible partition so check for reamaining word
                if(recHelper(k+1,s,wordSet,dp)){
                    return dp[i]=true;
                }
            }
        }

        return dp[i]=false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        // string cw="";
        int n=s.size();
        vector<int>dp(n,-1);

        return recHelper(0,s,wordSet,dp);
    }
