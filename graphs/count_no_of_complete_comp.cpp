vector<int>parent,edge,size;
public:
    int findParent(int a){
        if(parent[a]==a) return a;
        return parent[a]=findParent(parent[a]);
    }

    void unionBySize(int a,int b){
        a=findParent(a);b=findParent(b);
        if(a==b){
            edge[a]+=1;
            return;
        }
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        edge[a]+=(edge[b]+1);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.assign(n,0);size.assign(n,1);edge.assign(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto e:edges){
            unionBySize(e[0],e[1]);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]!=i) continue;
            if(edge[i]==(size[i]*(size[i]-1))/2) cnt+=1;
        }
        return cnt;
    }
