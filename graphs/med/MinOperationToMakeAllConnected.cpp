class DisjointSet{
    vector<int>parent,rank;
    public:

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

    }
    int findUltimateParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int up=parent[u];
        int  vp=parent[v];
        if(up==vp){
            return ;
        }
        if(rank[up]>rank[vp]){
            parent[vp]=up;
        }
        else if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else{
            parent[vp]=up;
            rank[up]+=1;
        }
    }
    
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dt(n);
        int edges=connections.size();
        int extraEdges=0;
        for(int i=0;i<edges;i++){
            int u=connections[i][0];
            int v=connections[i][1];

            if(dt.findUltimateParent(u)==dt.findUltimateParent(v)){
                extraEdges+=1;
            }
            dt.unionByRank(u,v);
            
        }

        int numOfComp=0;
        for(int i=0;i<n;i++){
            if(dt.findUltimateParent(i)==i){
                numOfComp+=1;
            }
        }

        if(extraEdges<numOfComp-1){
            return -1;
        }
        return numOfComp-1;
    }
};