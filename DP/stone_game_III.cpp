class Solution {
    vector<int>dp;
public:
    int recCount(int i,vector<int>&stoneValue){
        if(i==stoneValue.size()) return 0;
        if(dp[i]!=INT_MIN) return dp[i];

        int ans=INT_MIN,pSum=0;
        for(int j=0;j<3;j++){
            if(j+i==stoneValue.size()) break;
            pSum+=stoneValue[i+j];
            ans=max(ans,pSum-recCount(i+j+1,stoneValue));
        }
        return dp[i]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.assign(n,INT_MIN);
        int val=recCount(0,stoneValue);
        if(!val) return "Tie";
        if(val>0) return "Alice";
        return "Bob";
    }
};
