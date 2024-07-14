#include<iostream>
#include<list>
#include<vector>
#include<set>
using namespace std;


class Graph{
    int V;
    list<pair<int,int>> *l;
    public:
        Graph(int v){
            V=v;
            l=new list<pair<int,int>>[v+1];  //pair of node and weight
        }
        void addEdge(int i,int j,int wt,bool undir=true){
            l[i].push_back({j,wt});
            if(undir){
                l[j].push_back({i,wt});
            }
        }

        void dijkstra(int src,int dest,vector<int>& ans){
            vector<int> dist(V+1,INT_MAX);
            set<pair<int,int>>s; //{dist,int_node}
            vector<int> parent(V+1,0);
            dist[1]=0;
            s.insert({0,src}); 
            parent[src]=src; 
            while(!s.empty()){
                auto it=s.begin();
                int cd=it->first;
                int cn=it->second;
                s.erase(it);
                for(auto ngbr:l[cn]){
                    if(cd+ngbr.second<dist[ngbr.first]){
                        if(s.find({dist[ngbr.first],ngbr.first})!=s.end()){
                            s.erase({dist[ngbr.first],ngbr.first});
                        }
                        parent[ngbr.first]=cn;
                        dist[ngbr.first]=cd+ngbr.second;
                        s.insert({dist[ngbr.first],ngbr.first});
                    }
                    
                    
                }
            }
            if(dist[dest]==INT_MAX){  //edge case if there is no path
                ans.push_back(-1);
                return;
            }

            ans.push_back(dist[dest]); //storing the shortest dist
          
            int i=dest; 

            vector<int> path;
            
            while(i!=src){
                path.push_back(i);
                i=parent[i];

            }
            path.push_back(src);
            reverse(path.begin(),path.end());
            for(int x:path){
                ans.push_back(x); //storing the shortest path starting from src to dest
            }


        }


};


vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    Graph g(n);
    for(int i=0;i<m;i++){
        g.addEdge(edges[i][0],edges[i][1],edges[i][2]);
    }
    vector<int> ans;
    g.dijkstra(1,n,ans);
    
    return ans;
}


int main(){
    int n=5;
    int m=6;
    vector<vector<int>> e{{1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}};
    vector<int> a=shortestPath(n,m,e);
    for(auto x:a){
        cout<<x<<",";
    }
    cout<<endl;
}
