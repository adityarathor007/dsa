bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);

        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                queue<int>q;
                q.push(i);
                colors[i]=0;
                while(!q.empty()){
                    int cn=q.front();
                    q.pop();
                    int cc=colors[cn];
                    for(int neighbour:graph[cn]){
                        if(colors[neighbour]==-1){
                            colors[neighbour]=1-cc;
                            q.push(neighbour);
                        }
                        else{
                            if(cc==colors[neighbour]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
