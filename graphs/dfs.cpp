#include<iostream>
#include<list>
#include<queue>
#include<unordered_set>

using namespace std;

// class Graph{
//     int V;
//     list<int> *l;
//     public:

//     Graph(int v){
//         V=v;
//         l=new list<int>[V]; //dynamically allocate an array of V elements, where each element is a list<int>.
//     }

//     void addEdge(int i,int j,bool undir=true){
//         l[i].push_back(j);
//         if(undir){
//             l[j].push_back(i);
//         }
//     }

//     void dfsHelper(int node,bool *visited){
//         visited[node]=true;
//         cout<<node<<",";
//         for(auto x:l[node]){
//             if(!visited[x]){
//                 dfsHelper(x,visited);
//             }
           
//         }   
        
//     }


//     void dfs(int source){
//         bool *visited=new bool[V]{false};
//         dfsHelper(source,visited);
//         cout<<endl;

//     }


// };




// int main(){
//     Graph g(7);
//     g.addEdge(0,1);
//     g.addEdge(1,2);
//     g.addEdge(2,3);
//     g.addEdge(5,6);
//     g.addEdge(4,5);
//     g.addEdge(0,4);
//     g.addEdge(3,4);
//     g.dfs(1);
    

//     return 0;
// }


void dfs(int node,vector<int>&visited,vector<int>adj[],vector<int>&traversal){
        visited[node]=1;
        traversal.push_back(node);
        for(auto x:adj[node]){
            if(visited[x]==0){
                 dfs(x,visited,adj,traversal);
            }
           
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        vector<int>ans;
        
        dfs(0,visited,adj,ans);
        return ans;
    }


vector<int> *createAdjMatrix(int V,vector<pair<int,int>>&edges){
    vector<int>* adjMatrix = new vector<int>[V];
    for(auto p:edges){
        int u=p.first;
        int v=p.second;
        

        adjMatrix[u].push_back(v);
        adjMatrix[v].push_back(u);
    }

    return adjMatrix;

}

int main(){

    int V;
    cin>>V;
    int M;
    cin>>M;
    
    int u,v;



    vector<pair<int,int>>edges(M);
    for(int i=0;i<M;i++){
        
        cin>>u>>v;
        // cout<<u<<" - "<<v<<endl;
        edges[i]={u,v};
        

    }
    vector<int>* adj = createAdjMatrix(V,edges);
   
    

    auto traversal=dfsOfGraph(V,adj);

    for(auto x:traversal){
        cout<<x<<",";
    }
    cout<<endl;

    delete[] adj;
}