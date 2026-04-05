unordered_set<string>wordSt;
    vector<int>dp;
public:
    bool recCheck(int i,string &s){
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];

        string cw="";
        for(int j=i;j<s.size();j++){
            cw+=s[j];
            if(wordSt.count(cw)){
                if(recCheck(j+1,s)) return dp[i]=true;
            }
        }

        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            wordSt.insert(word);
        }
        int n=s.size();
        dp.assign(n,-1);
        return recCheck(0,s);
    }
