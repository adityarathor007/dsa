#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//using the node class created the graph ds
class Node{
    public:
    string name;
    list<string> nbrs;
    
    Node(string name){
        this->name=name;
    }
};

class Graph{
    unordered_map<string,Node*> t;
    public:
        Graph(vector<string> names){
            for(string name:names){
                t[name]=new Node(name);
            }
        }

        void addEdge(string x,string y,bool undir=true){
            t[x]->nbrs.push_back(y);
            if(undir){
                t[y]->nbrs.push_back(x);
            }
        }


        void printAdjList(){
            for(auto p:t){
                cout<<p.first<<"-> ";
                for(auto cs:p.second->nbrs){
                    cout<<cs<<',';
                }
                cout<<endl;
            }
        }
};



int main(){
    vector<string> cities={"New Delhi","Paris","New York","London","Dubai"};
    Graph g(cities);
    g.addEdge("New Delhi","Dubai");
    g.addEdge("New Delhi","Paris");
    g.addEdge("London","New York");
    g.addEdge("Paris","London");
    g.addEdge("New York","Dubai");
    g.printAdjList();


}