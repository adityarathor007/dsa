// A graph can have at most two Minimum Height Trees (MHTs) because the root of an MHT is always the
// center of the tree, which corresponds to the middle node(s) of the graph's longest path (diameter) and diameter can be both even or odd.

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};

        vector<int>degree(n,0);
        vector<vector<int>>adjList(n);
        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]]+=1;
            degree[edge[1]]+=1;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }
        int remaining=n;

        // onion slicing algorithm (removing leaves)
        // center of tree could be 1 or 2 (as the diameter of the tree could be even or odd)
        // we need the center because it gives us the MHT
        while(remaining>2){
            int size=q.size(); //for leaves at each step
            remaining-=size;
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                degree[node]=0;
                for(auto neighbour:adjList[node]){
                    degree[neighbour]-=1; //removing the leaves
                    if(degree[neighbour]==1) q.push(neighbour);
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
