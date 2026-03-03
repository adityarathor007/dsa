unordered_set<string>wordSet;
    vector<vector<int>>dp;
public:
    int recFind(int i,int si,string &s){
        if(i==s.size()){
            return i-si;
        }
        if(dp[i][si]!=-1) return dp[i][si];
        int o1=INT_MAX;
        string curr=s.substr(si,i-si+1);
        if(wordSet.count(curr)){
            o1=recFind(i+1,i+1,s);
        }
        else{
            o1=curr.size()+recFind(i+1,i+1,s);  //because subseq are not allowed
        }
        int o2=recFind(i+1,si,s);

        return dp[i][si]=min(o1,o2);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto word:dictionary){
            wordSet.insert(word);
        }
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return recFind(0,0,s);
    }
