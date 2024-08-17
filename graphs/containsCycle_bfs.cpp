#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfsTraversal(int node,vector<int>adj[],vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({node,-1}); //storing the node and the parent
        
        visited[node]=1;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int n=p.first;
            int par=p.second;
            cout<<par<<" - "<<n<<endl;
            for(auto x:adj[n]){
                if(visited[x]==0){
                    q.push({x,n});
                    visited[x]=1;
                }
                else if(visited[x]==1 and x!=par){
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
    
bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // using bfs
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(bfsTraversal(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
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