#include<iostream>
#include<list>
#include<queue>
#include<unordered_set>

using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:

    Graph(int v){
        V=v;
        l=new list<int>[V]; //dynamically allocate an array of V elements, where each element is a list<int>.
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void dfsHelper(int node,bool *visited){
        visited[node]=true;
        cout<<node<<",";
        for(auto x:l[node]){
            if(!visited[x]){
                dfsHelper(x,visited);
            }
           
        }   
        
    }


    void dfs(int source){
        bool *visited=new bool[V]{false};
        dfsHelper(source,visited);
        cout<<endl;

    }


};




int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.dfs(1);
    

    return 0;
}