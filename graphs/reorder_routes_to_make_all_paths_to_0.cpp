int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adjList;
        for(auto connection:connections){
            int n1=connection[0],n2=connection[1];
            adjList[n1].push_back({1,n2});
            adjList[n2].push_back({0,n1});  //because if the oppposite one leads to 0 then just to traverse on this one to see other edges which cant reach 0
        }
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(0);
        dist[0]=0;
        int ans=0;
        while(!q.empty()){
            auto cn=q.front();
            q.pop();
            for(auto [nd,nn]:adjList[cn]){
                if(dist[nn]==INT_MAX){
                    dist[nn]=dist[cn]+nd;
                    q.push(nn);
                    ans+=nd;
                }
            }
        }
        return ans;
    }
