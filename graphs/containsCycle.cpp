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
    
    
    
    bool dfsHelper(int node,bool* visited,int parent){
        bool ch=true;
        visited[node]=true;       
        for(auto x:l[node]){
            if(!visited[x]){
                bool nbrFindCycle=dfsHelper(x,visited,node);
                if(ch){
                    return true;
                }
            }
            //neighbour visited and is not the parent in the current dfs call
            else if(x!=parent){
                    return true;
            }
            
            
        }
        return false;
        
    
    }
    
    
};


bool contains_cycle(int v,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(v);
    
    for(pair<int,int>p:edges){
        g.addEdge(p.first,p.second,false);
    }
    bool* visited=new bool[v];
    return g.dfsHelper(0,visited,-1);
    
    
}


int main(){
    vector<pair<int,int> > in= {{0,1},{0,2},{2,1}};
    if(contains_cycle(3,in)){
        cout<<"contains cycle"<<endl;

    }
    else
        cout<<"does not contains cycle"<<endl;
}