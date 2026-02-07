vector<vector<int>>dp;
public:
    int recCalculate(int s,int e,vector<int>&cuts){
        if(s>e) return 0;

        if(dp[s][e]!=-1) return dp[s][e];

        int ans=INT_MAX;


        // try every possible cut k as the first cut in the range [s, e].
        // paying the cost of the current and when we chosse k then left side possible cuts are [s,k-1] and right side cuts are[k+1,e]
        for(int k=s;k<=e;k++){
            ans=min(ans,(cuts[e+1]-cuts[s-1])+recCalculate(s,k-1,cuts)+recCalculate(k+1,e,cuts));
        }

        return dp[s][e]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        dp.assign(m+2,vector<int>(m+2,-1));
        return recCalculate(1,m,cuts);
    }
