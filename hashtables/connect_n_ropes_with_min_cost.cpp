int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int num:arr) pq.push(num);

        int cost=0;
        while(pq.size()>1){
            int r1=pq.top();
            pq.pop();
            int r2=pq.top();
            pq.pop();
            cost+=r1+r2;
            pq.push(r1+r2);
        }

        return cost;

    }
