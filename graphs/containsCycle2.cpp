#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        V=v;
        l=new list<int>[V];

    }
    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    
    }

    bool dfsHelper(int n,bool* & visited,bool* & currentStack){
        currentStack[n]=true;
        visited[n]=true;
        for(auto x:l[n]){
            
            if(currentStack[x]){ //if it is a backedge vertex which is neighbour of current node is present in the current path already (2->3 then 2 wont be the neighbour of 3 as directed graph)
                return true;
            }
            else if(!visited[x]){ //checking for the child
                bool ngbrContainCycle=dfsHelper(x,visited,currentStack);
                if(ngbrContainCycle){
                    return true;
                }
            }
            
            
            
        }
        currentStack[n]=false;
        return false;
    }

};


bool contains_cycle(int v,vector<pair<int,int> > edges){
    //Complete this method]
    Graph g(v);
    for(auto p:edges){
        g.addEdge(p.first,p.second,false);

    }
    bool* visited= new bool[v];
    bool* currentStack=new bool[v];
    
    //what if from 0 the graph is not connected(i.e no path)  so we have to check all nodes if from a source if it is visited and if not then we apply dfs from it
    for(int i=0;i<v;i++){
        if(!visited[i]){ 
            if(g.dfsHelper(i,visited,currentStack)){
                return true;
            }
        }
    }
    return false;
    // return false;
    
}


int main(){
    int v=6;
    vector<pair<int,int> > in= {{0,1},{0,4},{0,5},{5,4},{0,1},{1,2},{2,3},{3,0}};
    if(contains_cycle(v,in)){
        cout<<"contains cycle"<<endl;

    }
    else
        cout<<"does not contains cycle"<<endl;
}