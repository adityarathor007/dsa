#include<iostream>
#include<list>
#include<queue>
#include<unordered_set>
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

        void bfs(int source){
            unordered_set<int> visited;
            queue<int> q;

            q.push(source);
            visited.insert(source);
           


            
            while(!q.empty()){
                int i=q.front();
                q.pop();
                cout<<i<<endl;
                for(int n:l[i]){
                    
                    if(visited.find(n)==visited.end()){
                        q.push(n);
                        visited.insert(n); 
                        
                    }
                }
            }

            return ;

        }

        void shortest_path_bfs(int source){
            unordered_set<int> visited;
            queue<int> q;
            int *dist=new int[V]{0};  //dynamically allocation of array
            int *parent=new int[V];

            for(int i=0;i<V;i++){
                parent[i]=-1;
            }


            q.push(source);
            visited.insert(source);
            parent[source]=source;
    


            
            while(!q.empty()){
                int i=q.front();
                q.pop();
                cout<<i<<endl;
                for(int n:l[i]){
                    
                    if(visited.find(n)==visited.end()){
                        dist[n]=dist[i]+1;
                        parent[n]=i;  //updating the parent of the node
                        q.push(n);
                        visited.insert(n); 
                        
                    }
                }

            }
                //print the shortest distance
                for(int i=0;i<V;i++){
                    cout<<"The shortest distance of the node "<<i<<"from the source is: "<<dist[i]<<endl;
                }

                //print the shortest path from source to all nodes in the graph
                for(int i=0;i<V;i++){
                    int temp=i;
                    while(temp!=source){
                        cout<<temp<<"--";
                        temp=parent[temp];
                    }
                    cout<<source<<endl;
                }


           

            return ;

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
            g.bfs(1);
            g.shortest_path_bfs(1);

            return 0;

}