unordered_set<string>st;
    unordered_map<int,vector<string>>dp;
public:
    vector<string> recFind(int i,string& s){
        if(dp.count(i)) return dp[i];
        vector<string>res;
        if(i==s.size()){
            res.push_back("");
            return dp[i]=res;
        }

        string cw="";

        for(int j=i;j<s.size();j++){
            cw+=s[j];

            if(st.count(cw)){
                vector<string> nxt=recFind(j+1,s);
                for(string str:nxt){
                    if(str==""){ //cw is the last word
                        res.push_back(cw);
                    }
                    else res.push_back(cw+" "+str);
                }
            }
        }

        return dp[i]=res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word:wordDict){
            st.insert(word);
        }
        return recFind(0,s);
    }
