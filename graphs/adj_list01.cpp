#include<iostream>
#include<list>
using namespace std;
//this requires to specify the number of nodes


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

        void printAdjList(){
            for(int i=0;i<V;i++){
                cout<<i<<"--> ";
                for(int x:l[i]){
                    cout<<x<<",";
                }
                cout<<endl;
            }
            
        }


};



int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.printAdjList();
    cout<<endl;
    return 0;

}