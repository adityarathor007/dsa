long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=costs.size();
        cout<<n<<endl;
        int i=0;
        int j=n-1;
        for(int ind=0;ind<candidates;ind++){
            if(i>j) break;
            pq.push({costs[i],i});
            i+=1;
            if(i>j) break;
            pq.push({costs[j],j});
            j-=1;
        }

        long long total_cost=0;
        
        while(k>0){
            auto [min_cost,index]=pq.top();
            pq.pop();
            total_cost+=min_cost;
            if(i<=j){
                if(index<i){
                    pq.push({costs[i],i});
                    i+=1;
                }
                else{
                    pq.push({costs[j],j});
                    j-=1;
                }
            }

            k-=1;
        }
        return total_cost;
    }

    }
