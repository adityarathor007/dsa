#include<iostream>
#include<list>
#include<set>
using namespace std;
class Graph{
    int V;
    list<pair<int,int> > *l;  //{wt,ngbr}
    public:
    Graph(int v){
        V=v;
        l=new list<pair<int,int>>[V];   

    }
    void addEdge(int i,int j,int wt,bool undir=true){
        l[i].push_back({wt,j});
        if(undir){
            l[j].push_back({wt,i});
        }
    
    }

    int dijkstra(int src,int dest){

        //DataStr
        vector<int> dist(V,INT_MAX); //all dist before traversal set to infinity
        set<pair<int,int>> s; //store the {dist,node}

        //init
        dist[src]=0;
        s.insert({0,src});


        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int distTillNow=it->first;
            s.erase(it); //Pop out the first node with the minimum value

            // iterate over the neighbour of the nodes
            for(auto ngbrPair:l[node]){
                int ngbr=ngbrPair.second;
                int currEdgeWt=ngbrPair.first;

                if(distTillNow+currEdgeWt<dist[ngbr]){
                    //remove if such pair already exist in the set and add with the new value
                    auto f=s.find({dist[ngbr],ngbr});
                    if(f!=s.end()){
                        s.erase(f); 
                    }
                    

                    dist[ngbr]=distTillNow+currEdgeWt;
                    s.insert({dist[ngbr],ngbr}); 
                }

            }
        }
        //printing the single shortest distance from the src to all other nodes
        for(int i=0;i<V;i++){
            cout<<"the shortest dist from the src: "<<src<<"to the node: "<<i<<" -> "<<dist[i];
            cout<<endl;
        }


        return dist[dest];



    }


};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);   
    cout<<g.dijkstra(0,4)<<endl;


}