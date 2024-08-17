#include<iostream>
#include <vector>
#include<queue>
using namespace std;


bool dfsTraversal(int node,vector<int> adj[],vector<int> &visited,int parent){
    
    visited[node]=1;

    for(auto x:adj[node]){
        if(visited[x]==0){
            bool ch=dfsTraversal(x,adj,visited,node);
            if(ch){
                return true;
            }
        }
        else if(x!=parent){
            return true;
        }
        
    }
    return false;


}


bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // using dfs
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfsTraversal(i,adj,visited,-1)){
                    cout<<i<<endl;
                    return true;
                }
            }
        }
        return false;
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
    
    // for(int i=0;i<V;i++){
    //     for(auto x:adj[i]){
    //         cout<<x<<",";
    //     }
    //     cout<<endl;
    // }
    

    if(isCycle(V,adj)){
        cout<<"cycle is there"<<endl;
    }
    else{
        cout<<"cycle not present"<<endl;
    }

    return 0;

}