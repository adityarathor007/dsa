long long int wineSelling(vector<int>& Arr, int N) {
        // Code here.
        // Greedy solution of finding the nearest source for selling
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<N;i++){
            if(Arr[i]<0) pq.push({i,-Arr[i]});
        }
        long long int cost=0;
        for(int i=0;i<N;i++){
            if(Arr[i]>0){
                int val=Arr[i];
                while(val>0){
                    auto [ind,cnt]=pq.top();
                    pq.pop();
                    int sell=min(cnt,val);
                    cost+=abs(ind-i)*sell;
                    val-=sell;
                    if(cnt>sell) pq.push({ind,cnt-sell});
                }
            }
        }

        return cost;
    }
