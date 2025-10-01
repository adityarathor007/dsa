
class DisjointSet{
    vector<int>parent,rank;

    public:
        DisjointSet(int V){
            rank.resize(V,0);
            parent.resize(V);
            for(int i=0;i<V;i++){
                parent[i]=i;
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
};




// struct Edge{
//     int wt;
//     int node;
//     int parent;
//     Edge(int a,int b,int c){
//         wt=a;node=b;parent=c;
//     }
// };

// struct CompareByWeight{
//     bool operator()(const Edge&a,const Edge&b){
//         return a.wt>b.wt;
//     }

// };


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here

        // USING THE PRIM'S ALGORITHM
        // vector<vector<int>>adjMatrix(V,vector<int>(V));
        // for(int i=0;i<edges.size();i++){
        //     int n1=edges[i][0];
        //     int n2=edges[i][1];
        //     int wt=edges[i][2];
        //     adjMatrix[n1][n2]=wt;
        //     adjMatrix[n2][n1]=wt;
        // }



        // priority_queue<Edge,vector<Edge>,CompareByWeight>pq;
        // pq.push(Edge(0,0,-1));
        // vector<int>visited(V,0);
        // int sum=0;

        // while(!pq.empty()){
        //     Edge curr=pq.top();
        //     pq.pop();

        //     int n1=curr.node;
        //     int parent=curr.parent;


        //     if(visited[n1]!=0){
        //         continue;
            // }


        //     visited[n1]=1;


        //     if(parent!=-1){
        //         // cout<<"the nodes are: "<<n1<<" and "<<parent<<endl;
        //         sum+=curr.wt;
        //     }

        //     for(int i=0;i<V;i++){
        //         if(adjMatrix[n1][i]!=0 and visited[i]==0){
        //             pq.push(Edge(adjMatrix[n1][i],i,n1));

        //         }

        //     }
        // }


        // return sum;





        // USING THE KRUSKAL ALGORITHM

        vector<pair<int,pair<int,int>>>wt_edges;
        for(auto edge:edges){
            int n1=edge[0];
            int n2=edge[1];
            int wt=edge[2];
            wt_edges.push_back({wt,{n1,n2}}); //even though the graph is undirected we push it one time as kruskal will ignore the duplicate one
        }

        sort(wt_edges.begin(),wt_edges.end());
        djs=DisjointSet(V);

        int minWt=0;
        for(int it:wt_edges){
            int wt=it.first;
            int n1=it.second.first;
            int n2=it.second.second;
            if(djs.findParent(n1)!=djs.findParent(n2)){
                djs.unionByRank(n1,n2);
                minWt+=wt;
            }

        }

    return wt;

    }
};
