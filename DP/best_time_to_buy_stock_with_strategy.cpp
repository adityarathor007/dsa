long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>pSum(n,0);
        pSum[0]=prices[0]*strategy[0];
        long long modify=0,k2=k/2;

        for(int i=1;i<n;i++){
            pSum[i]=pSum[i-1]+prices[i]*strategy[i];
            modify+=(-(i>=k2 & i<k)&prices[i]);
        }

        long long profit=max(pSum[n-1],modify+pSum[n-1]-pSum[k-1]);

        for(int i=1;i+k-1<n;i++){
            modify+=prices[i+k-1]-prices[i+k2-1];
            profit=max(profit,modify+pSum[n-1]-pSum[i+k-1]+pSum[i-1]);
        }

        return profit;
    }
