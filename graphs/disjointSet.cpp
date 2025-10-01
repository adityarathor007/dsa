class DisjointSet(){
    vector<int>parent,rank;

    public:
        DisjointSet(int V){
            rank.resize(V,0)
            parent.resize(V);
            for(int i=0;i<V;i++){
                parent[i]=i
            }
        }

        int findParent(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x]=findParent(parent[x]);

        }

        void unionByRank(int x,int y){
            int upx=findParent(x);
            int upy=findParent(y);
            if(rank[upx]>rank[upy]){
                parent[upy]=upx;
            }
            else if(rank[upx]<rank[upy]){
                parent[upx]=upy;
            }
            else{
                parent[upy]=upx;
                rank[upx]+=1;
            }
        }
}
