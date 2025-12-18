class Solution {
public:
    long long recHelper(int i, int curr, int transactionStatus, int &k, vector<int>&prices,vector<vector<vector<long long>>>&dp){
        if(curr/2==k) return 0;
        if(i==prices.size()){
            if(curr&1) return INT_MIN;
            return 0; //atmost k transaction
        }

        if(dp[i][curr][transactionStatus]!=-1) return dp[i][curr][transactionStatus];

        if(!(curr&1)){
            long long o1=-prices[i]+recHelper(i+1,curr+1,1,k,prices,dp);
            long long o2=recHelper(i+1,curr,0,k,prices,dp);
            long long o3=prices[i]+recHelper(i+1,curr+1,2,k,prices,dp);
            dp[i][curr][transactionStatus]=max(o1,max(o2,o3));

            return  dp[i][curr][transactionStatus];
        }

        long long o1;
        if(transactionStatus==1){
            o1=prices[i]+recHelper(i+1,curr+1,0,k,prices,dp);
        }
        else{
            o1=-prices[i]+recHelper(i+1,curr+1,0,k,prices,dp);
        }
        long long o2=recHelper(i+1,curr,transactionStatus,k,prices,dp);
        return dp[i][curr][transactionStatus]=max(o1,o2);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(2*k+1,vector<long long>(3,-1)));
        return recHelper(0,0,0,k,prices,dp);
    }
};
