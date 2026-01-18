struct Edge{
    int i;
    int j;
    int dist;
    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }

};

class DisjointSet{
    vector<int>parent,rank;
public:
    DisjointSet(int n){
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;
        if(rank[pv]>rank[pu]) swap(pu,pv);
        parent[pv]=pu;
        if(rank[pu]==rank[pv]) rank[pu]+=1;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int total=0;
        vector<Edge>edges;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dist});
            }
        }
        sort(edges.begin(), edges.end());
        int num_edges=edges.size();
        if(num_edges==0) return 0;

        DisjointSet djs=DisjointSet(n);

        int edgesUsed = 0;
        for (auto &e : edges) {
            if (djs.findParent(e.i) != djs.findParent(e.j)) {
                djs.unionByRank(e.i, e.j);
                total += e.dist;
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }

        return total;
    }
};
