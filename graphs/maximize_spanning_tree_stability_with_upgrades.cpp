class DSU{
    vector<int>rank;
    vector<int>parent;
public:
    DSU(int n){
        rank.assign(n,0);
        parent.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);
        if(up==vp) return;
        if(rank[up]<rank[vp]){
            swap(up,vp);
        }
        parent[vp]=up;
        if(rank[up]==rank[vp]) rank[up]+=1;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans=INT_MAX;
        vector<vector<int>>temp;
        DSU dsu(n);
        int req=n-1;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(edge[3]==1){
                if(dsu.findParent(u)==dsu.findParent(v)) return -1;
                dsu.unionByRank(u,v);
                ans=min(ans,edge[2]);
                req-=1;
            }
            else temp.push_back({u,v,edge[2]});
        }

        if(!req) return ans;

        sort(temp.begin(),temp.end(),[](auto& a,auto& b){
            return a[2]>b[2];
        });

        for(auto edge:temp){
            int u=edge[0];
            int v=edge[1];
            if(dsu.findParent(u)==dsu.findParent(v)) continue;
            dsu.unionByRank(u,v);
            int s=edge[2];
            if(req<=k){ //it ensures that the ans remains max by not disturbing the heavier edges and for the smaller edges also we try to get double so that the min gets maximized
                s*=2;
                k-=1;
            }
            ans=min(ans,s);
            req-=1;
        }
        if(req>0) return -1;  //not all nodes covered
        return ans;
    }
};
