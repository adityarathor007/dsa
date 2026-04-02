class DisjointSet{
        vector<int>rank,parent;
    public:
        DisjointSet(int n){
            rank.assign(n,0);
            parent.assign(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=findParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int up=findParent(u);
            int vp=findParent(v);
            if(up==vp) return;
            if(rank[up]<rank[vp]) swap(up,vp);
            parent[vp]=up;
            if(rank[up]==rank[vp]) rank[up]+=1;
        }
};

class Solution {
public:
    int getMST(int n,vector<vector<int>>& edges,vector<int>reqd){
        DisjointSet djs=DisjointSet(n);
        int sum=0;
        int cnt=0;
        int m=edges.size();
        if(!reqd.empty()){
            djs.unionByRank(reqd[0],reqd[1]);
            sum+=reqd[2];
            cnt+=1;
        }
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            if(djs.findParent(u)!=djs.findParent(v)){
                djs.unionByRank(u,v);
                sum+=wt;
                cnt+=1;
            }
        }
        return cnt!=n-1?INT_MAX:sum;
    }


    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto& e1,auto& e2){
            return e1[2]<e2[2];
        });
        int baseline=getMST(n,edges,{});
        vector<vector<int>>ans(2);

        for(int i=0;i<m;i++){
            vector<vector<int>>temp=edges;
            temp.erase(temp.begin()+i);
            int curr=getMST(n,temp,{});
            int ind=edges[i][3];
            if(curr>baseline) ans[0].push_back(ind);
            else{
                int v2=getMST(n,edges,edges[i]);
                if(v2==baseline) ans[1].push_back(ind);
            }
        }

        return ans;

    }
};
