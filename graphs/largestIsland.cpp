#include<iostream>
#include<vector>
using namespace std;

void dfsHelper(vector<vector<int>> &grid, int &c, int i, int j)
{
    c += 1;
    int n = grid.size();
    int m = grid[0].size();
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    grid[i][j]=0;
  
        cout<<i<<j<<endl;
        cout<<"the count untill now "<<c<<endl;
        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1)
            {
              
                dfsHelper(grid,c,nx,ny);
            }
        }
    
    

    return ;
}

int largestIsland(vector<vector<int>> grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int maxc=0;
    int c=0;


    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if (grid[i][j] == 1)
            {
                c = 0;
                dfsHelper(grid,c, i, j); //1 as we started counting from that island
            }

        if (c > maxc)
            {
                maxc = c;
            }
    }}
    return maxc;
}

int main(){
    vector<vector<int>>grid= {{1,0,0,1,0},{1,0,1,0,0},{0,0,1,0,1},{1,0,1,1,1},{1,0,1,1,0}};
    // vector<vector<int>>grid= {{0,0,0,0,0},{0,0,1,0,0}};

    cout<<largestIsland(grid)<<endl;
}