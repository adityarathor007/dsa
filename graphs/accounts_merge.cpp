class DisjointSet {
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
        return ;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size(); //maximum number of unique accounts
        DisjointSet djs(n);
        unordered_map<string,int>mpMailToNode;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string ce=accounts[i][j];
                if(!mpMailToNode.count(ce)) mpMailToNode[ce]=i;
                else{
                    djs.unionByRank(mpMailToNode[ce],i);
                }
            }
        }
        vector<vector<string>>merged(n);
        for(auto [ce,ind]:mpMailToNode){
            string name=accounts[ind][0];
            int pi=djs.findParent(mpMailToNode[ce]);
            if(merged[pi].empty()) merged[pi].push_back(name);
            merged[pi].push_back(ce);
        }

        vector<vector<string>>ans;
        for(auto vec:merged){
            if(vec.empty()) continue;
            sort(vec.begin()+1,vec.end());
            ans.push_back(vec);
        }
        return ans;
    }
};
