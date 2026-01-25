class disjointSet{
    vector<int>parent,rank;
    public:
        disjointSet(int n){
            rank.assign(n,0);
            parent.assign(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int findUltimateParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=findUltimateParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int up=findUltimateParent(u);
            int vp=findUltimateParent(v);
            if(up==vp) return;
            if(rank[vp]>rank[up]) swap(up,vp);
            parent[vp]=up;
            if(rank[up]==rank[vp]) rank[up]+=1;

        }
};

class Solution {
public:
    bool isSimilar(string s1,string s2){
        if(s1==s2) return true;
        int mismatch=0;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) mismatch+=1;
        }

        return mismatch==2;

    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        disjointSet dsu=disjointSet(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    dsu.unionByRank(i,j);
                }
            }
        }

        int grps=0;
        for(int i=0;i<n;i++){
            if(dsu.findUltimateParent(i)==i) grps+=1;
        }

        return grps;

    }
};
