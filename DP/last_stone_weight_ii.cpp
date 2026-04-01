class Solution {
    vector<vector<int>>dp;
public:
    int recSolve(int i,int target,vector<int>&stones){
        if(i==stones.size()){
            return target>=0?0:INT_MIN;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int o1=INT_MIN;
        if(stones[i]<=target){
            o1=stones[i]+recSolve(i+1,target-stones[i],stones);
        }
        int o2=recSolve(i+1,target,stones);
        return dp[i][target]=max(o1,o2);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(int stone:stones){
            total+=stone;
        }
        int target=total/2;
        int n=stones.size();
        dp.assign(n,vector<int>(target+1,-1));
        int s1=recSolve(0,target,stones);
        return total-2*s1;
    }
};
