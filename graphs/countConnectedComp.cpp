#include<iostream>
#include<vector>
using namespace std;


// using adjMatrix(gfg)
// class Solution {
//   public:
//     void dfsTraversal(int node,vector<vector<int>> &adjMatrix,vector<int>&visited){
//         visited[node]=1;
//         for(int i=0;i<adjMatrix[node].size();i++){
//             if(adjMatrix[node][i]==1 and visited[i]==0){
//                 dfsTraversal(i,adjMatrix,visited);
//             }
            
//         }
//         return ;
        
//     }
  
//     int numProvinces(vector<vector<int>> adj, int V) {
//         // code here
//         vector<int>visited(V,0);
//         int ans=0;
        
//         for (int i = 0; i < V; i++) {
//             if(visited[i]==0){
//                 ans+=1;
//                 dfsTraversal(i,adj,visited);
//             }
            
//         }
        
//         return ans;
        
            
//     }
// };


//solution using adj list
void traverse(int node,vector<vector<int>>&adjList,vector<int>&visited){
    visited[node]=1;

    
    for(auto x:adjList[node]){
        if(visited[x]==0){
            traverse(x,adjList,visited);
        }
    }
    return ;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};

    }
    

    vector<vector<int>>adjList(n);

    

    
    for(auto p:edges){
        adjList[p.first].push_back(p.second);
        adjList[p.second].push_back(p.first);
    }

    // for (int i = 0; i < n; i++ ) {
    //     for(int x:adjList[i]){
    //         cout<<x<<",";
    //     }
    //     cout<<endl;
    // }
    

    vector<int>visited(n,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count+=1;
            traverse(i,adjList,visited);
        }
    }

    cout<<count<<endl;

    return 0;
}
