class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adjList;
        for(auto time:times){
            adjList[time[0]].push_back({time[1],time[2]});
        }
        int time=0;
        vector<int>visited(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            int size=pq.size();
            int max_time=0;

            auto [wt,node]=pq.top();
            pq.pop();
            if(!visited[node]) time=max(wt,time);
            visited[node]=1;

            for(auto [neighbour,next_wt]:adjList[node]){
                if(!visited[neighbour]){
                    pq.push({next_wt+wt,neighbour});
                }
            }

        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                // cout<<i<<endl;
                return -1;
            }
        }

        return time;
    }
};
