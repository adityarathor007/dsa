 vector<vector<int>> dirn{{-1,0},{0,1},{1,0},{0,-1}};

    bool isValid(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n) return true;
        return false;
    }


    void dfs(int i,int j,vector<vector<char>>&grid){

        grid[i][j]='2';

        int m=grid.size();
        int n=grid[0].size();

        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];
            int ny=j+dirn[k][1];
            if(isValid(nx,ny,m,n) and grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }
        }

        return ;

    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='1'){
                ans+=1;
                dfs(i,j,grid);
               }
            }
        }

        return ans;
    }
