 vector<vector<int>>dp;
public:
    bool recSolve(int i,int j,string& p,string& s){
        if(i==p.size()){
            return j==s.size(); //because we have no option of skipping in s
        }

        bool isMatch=(j<s.size() and (p[i]==s[j] || p[i]=='.'));

        if(i+1<p.size() and p[i+1]=='*'){
            bool o1=recSolve(i+2,j,p,s); //skipping the pattern
            bool o2=isMatch and recSolve(i,j+1,p,s); //moving to the next in s (only if it matched)
            return dp[i][j]=(o1 or o2);
        }


        return dp[i][j]=(isMatch and recSolve(i+1,j+1,p,s)); //normally moving both 1 forward (only when there is no next star)
    }
    bool isMatch(string s, string p) {
        dp.assign(25,vector<int>(25,-1));  //because we have option of skipping even if s is completed
        return recSolve(0,0,p,s);
    }
