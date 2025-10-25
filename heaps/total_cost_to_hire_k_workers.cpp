long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        int n=costs.size();
        int i=0,j=n-1;
        long long ans=0;
        while(k--){
            while(pq1.size()<candidates and i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates and i<=j){
                pq2.push(costs[j--]);
            }

            int t1=pq1.size()>0?pq1.top():INT_MAX;
            int t2=pq2.size()>0?pq2.top():INT_MAX;

            if(t1<=t2){
                ans+=t1;
                pq1.pop();
            }
            else{
                ans+=t2;
                pq2.pop();
            }

        }
        return ans;

    }