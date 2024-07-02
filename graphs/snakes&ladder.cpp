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
            l=new list<int>[V];
        }

        void addEdge(int i,int j,bool undir=true){
            l[i].push_back(j);
      
            if(undir){
                l[j].push_back(i);
            }
        }


        int findShortestPathTraversal(int start,int dest){
            
            queue<int> q;
            unordered_set<int> visited;
            int *dist=new int[V]{0};
            q.push(start);
            visited.insert(start);
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto n:l[x]){
                    if(visited.find(n)==visited.end()){
                        q.push(n);
                        dist[n]=dist[x]+1;
                        visited.insert(n);
                    }
                }
            }


        return dist[dest];

        }
    

};

int min_dice_throws(int n,vector<pair<int,int> > snakes,vector<pair<int,int> > ladders){
    Graph g(n+1);
    vector<int> board(n+1,0);

    //storing the deltas of ladders and snakes
    for(auto s:snakes){
        board[s.first]=s.second-s.first; //negative delta as value get removed as reaching snake(s.second is the tail)
    }

    for(auto s:ladders){
        board[s.first]=s.second-s.first;
    }


    for(int i=1;i<n;i++){
        for(int dice=1;dice<=6;dice++){
            int v=i+dice;
            v+=board[v];
            if(v<=n){
                g.addEdge(i,v,false);
            }
            
        }
    }

    return g.findShortestPathTraversal(1,n);




}




int main(){
    int n=36;
    vector<pair<int,int> > snakes={{17,4},{24,15},{20,6},{32,30},{34,12}};
    vector<pair<int,int> > ladders={{2,15},{5,7},{9,27},{18,29},{25,35}};
    cout<<min_dice_throws(n,snakes,ladders)<<endl;


}