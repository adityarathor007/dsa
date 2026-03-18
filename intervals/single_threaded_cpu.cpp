 vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        long long time=0;
        vector<int>ans;
        while(!pq.empty() or i<n){
            if(pq.empty()){
                time=max(time,(long long) tasks[i][0]); //either exceeded the next task time or it is idle
            }
            while(i<n and time>=tasks[i][0]){ //insert all task which start before before the current time
                pq.push({tasks[i][1],tasks[i][2]});
                i+=1;
            }
            auto [len,ind]=pq.top();
            pq.pop();
            time+=len;
            ans.push_back(ind);
        }
        return ans;
    }
