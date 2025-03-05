class Solution{
 public:
    // Function to find the number of islands.
    void dfsTraversal(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited){
        
        visited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>dx{0,-1,-1,-1,0,1,1,1};
        vector<int>dy{-1,-1,0,1,1,1,0,-1};
        for(int k=0;k<8;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and ny>=0 and nx<n and ny<m and visited[nx][ny]==0 and grid[nx][ny]=='1'){
                dfsTraversal(nx,ny,grid,visited);
            }
            
        }
    
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 and grid[i][j]=='1'){
                    dfsTraversal(i,j,grid,visited);
                    ans+=1;
                }
            }
        }
        
        return ans;
        
    }

};