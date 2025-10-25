int dfs(int node,vector<int>&visited,vector<vector<int>>&adjList){
        visited[node]=1;
        int ans=0;
        for(int neighbor:adjList[node]){
            if(!visited[abs(neighbor)]){
                int v1=dfs(abs(neighbor),visited,adjList);
                int v2=(neighbor>0);  //the edges that needs to be reversed
                ans+=(v1+v2);
            }
        }
        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>visited(n);
        vector<vector<int>>adjList(n);
        for(auto edge:connections){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(-edge[0]);
        }
        return dfs(0,visited,adjList);
    }