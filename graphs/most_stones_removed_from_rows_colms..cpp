class Solution {
    vector<int>parent,rank;
    int findUltimateParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionByRank(int n1,int n2){
        int up1=findUltimateParent(n1);
        int up2=findUltimateParent(n2);
        if(up1==up2) return ;
        if(rank[up1]<rank[up2]) swap(up1,up2);
        parent[up2]=up1;
        if(rank[up1]==rank[up2]) rank[up1]+=1;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int r,c=0;
        for(auto stone:stones){
            r=max(r,stone[0]+1);
            c=max(c,stone[1]+1);
        }

        parent.assign(r+c,-1);
        rank.assign(r+c,0);
        for(auto stone:stones){
            int n1=stone[0];
            int n2=r+stone[1];
            if(parent[n1]==-1) parent[n1]=n1;
            if(parent[n2]==-1) parent[n2]=n2;
        }

        for(auto stone:stones){
            int n1=stone[0];
            int n2=r+stone[1];
            unionByRank(n1,n2);
        }

        int cc_comps=0;
        for(int i=0;i<r+c;i++){
            if(parent[i]==i) cc_comps+=1;
        }
        return n-cc_comps;

    }
};
