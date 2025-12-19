class Solution {
    vector<int>parent,rank;

    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionFn(int u,int v){
        int uu=findUParent(u);
        int uv=findUParent(v);
        if(uu==uv) return;
        if(rank[uu]<rank[uv]) swap(uu,uv);
        parent[uv]=uu; //make the node as ultimate parent which has more rank
        if(rank[uu]==rank[uv]) rank[uu]+=1;
        return ;

    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1,-1);
        rank.resize(n+1,0);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        vector<int>ans;

        //creating disjoint set using edges
        for(auto& edge:edges){
            int n1=edge[0],n2=edge[1];

            // here instead of checking the parent array we are checking by the main function as it is possible that even after union all children nodes parent are not updated
            if(findUParent(n1)==findUParent(n2)){  //if their ultimate parents are same then this edge is extra and can be removed
                ans.push_back(n1);
                ans.push_back(n2);
                continue;
            }
            unionFn(n1,n2);
        }

        return ans;

    }
};
