    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n=capital.size();
        int curr=0;

        vector<vector<int>>combined;
        for(int i=0;i<n;i++){
            combined.push_back({capital[i],profits[i]});
        }

        sort(combined.begin(),combined.end());
        priority_queue<int>pq;

        while(k--){
            while(curr<n and w>=combined[curr][0]) pq.push(combined[curr++][1]);
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }

        return w;


    }
