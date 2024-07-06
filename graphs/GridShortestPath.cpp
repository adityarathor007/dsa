#include<iostream>
#include<set>
#include<vector>
#include <limits.h>
using namespace std;


class Node{
    public:
    int data;
    int i;
    int j;
    Node(int x,int y,int d){
        data=d;
        i=x;
        j=y;

    }

    
};


class Compare{
    public:
        bool operator()(const Node &a1, const Node &a2) const
        {
            return a1.data <= a2.data;
        }
};







int shortest_path(vector<vector<int>> grid)
{
    // return the shortest path len

    int n=grid.size();
    int m=grid[0].size();

    // cout<<n<<endl;
    // cout<<m<<endl;

    vector<vector<int>> vec(n, vector<int>(m,INT_MAX));
    
    
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    
    set<Node,Compare> s;
    
    
    s.insert(Node(0, 0, grid[0][0]));
    vec[0][0]=grid[0][0];
    

    while(!s.empty()){
        auto it=s.begin();
        int cx=it->i;
        int cy=it->j;   
        int cd=it->data;
        s.erase(it);
  


        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            
          
            if(nx>=0 and ny>=0 and nx<n and ny<m and cd+grid[nx][ny]<vec[nx][ny]){
                // cout << "the value of dist untill now:" << cd << endl;
                // cout << "the cost to pay" << grid[nx][ny] << endl;
                

                // cout<<"the value of nx and ny on which we move"<<nx<<","<<ny<<endl;
                //Remove the old node from the set if it exist so as to update
                Node temp(nx,ny,vec[nx][ny]);
                if(s.find(temp)!=s.end()){
                    s.erase(s.find(temp));
                }
                
                //insert the new node in the set
                int nd=grid[nx][ny]+cd;
                vec[nx][ny]=nd;
                s.insert(Node(nx,ny,nd));


            }
        }

    }
    return vec[n-1][m-1];

}

int main(){

    vector<vector<int>> grid = {{31, 100, 65, 12, 18}, {10, 13, 47, 157, 6}, {100, 113, 174, 11, 33}, {88, 124, 41, 20, 140}, {99, 32, 111, 41, 20}};
    // vector<vector<int>> grid = {{31, 100, 40},{10,11,21}};
    cout<<shortest_path(grid)<<endl;
}