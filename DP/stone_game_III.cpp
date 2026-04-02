vector<vector<vector<int>>>dp;
public:
    int recSolve(int i,int M,int turn,vector<int>&piles){
        if(i>=piles.size()) return 0;
        if(dp[i][M][turn]!=-1) return dp[i][M][turn];
        if(turn){
            int ans=0;
            int psum=0;
            for(int x=1;x<=2*M;x++){
                if(i+x-1>=piles.size()) break;
                psum+=piles[i+x-1];
                ans=max(ans,psum+recSolve(i+x,max(M,x),!turn,piles));
            }
            return dp[i][M][turn]=ans;
        }
        int ans=1e9;
        for(int x=1;x<=2*M;x++){
            if(i+x-1>=piles.size()) break;
            ans=min(ans,recSolve(i+x,max(M,x),!turn,piles));
        }
        return dp[i][M][turn]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<vector<int>>(105,vector<int>(2,-1)));
        return recSolve(0,1,1,piles);
    }
