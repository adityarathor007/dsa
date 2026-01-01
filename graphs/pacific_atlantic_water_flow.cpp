vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int i,int j,int rows,int colms){
        if(i>=0 and j>=0 and i<rows and j<colms) return true;
        return false;
    }

    void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&heights){
        int rows=visited.size();
        int colms=visited[0].size();

        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];       cout<<i<<" "<<j<<endl;
            int ny=j+dirn[k][1];
            if(isValid(nx,ny,rows,colms) and !visited[nx][ny] and heights[nx][ny]>=heights[i][j]) dfs(nx,ny,visited,heights);
        }
        return ;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dfs(0,i,pacific,heights);
            dfs(m-1,i,atlantic,heights);
        }

        for(int i=0;i<m;i++){
            dfs(i,0,pacific,heights);
            dfs(i,n-1,atlantic,heights);
        }

        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] and atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
